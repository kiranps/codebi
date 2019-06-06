open Css;
open Widget.Types;
open GridLayout.Types;

Utils.require("react-grid-layout/css/styles.css");

let breakpoints = [%raw
  {|
    {lg: 1200, md: 996, sm: 768, xs: 480, xxs: 0}
  |}
];

let cols = [%raw {|
    {lg: 12, md: 12, sm: 12, xs: 12, xxs: 12}
  |}];

let widget =
  style([
    boxSizing(borderBox),
    borderRadius(px(4)),
    backgroundColor(white),
    padding(px(10)),
    boxShadow(
      ~x=px(0),
      ~y=px(2),
      ~blur=px(5),
      ~inset=false,
      rgba(0, 0, 0, 0.1),
    ),
  ]);

let createLayouts = x => gridLayout(~lg=x);

let generateLayout = arr =>
  arr
  |> Array.mapi((i, widget) =>
       layout(~w=4, ~h=4, ~x=i mod 3 * 4, ~y=i / 3 * 3, ~i=widget.id)
     )
  |> createLayouts;

module GridContainer = {
  let container = style([backgroundColor(`hex("f0f3f4a8"))]);

  [@react.component]
  let make = (~children) => <div className=container> children </div>;
};

[@react.component]
let make = _ => {
  let (widgets, setWidgets) = React.useState(() => [||]);
  let (resizeWidgetId, setResizeWidgetId) =
    React.useState(() => Some(("", 0, 0)));
  let width = Hooks.useWindowSize() - 10; /* change to document.body.scrollWidth */

  React.useEffect0(() => {
    Js.Promise.(
      Widget.Api.fetchAll()
      |> then_(json =>
           (
             switch (json) {
             | Widgets(data) => setWidgets(_ => data)
             | Failure => setWidgets(_ => [||])
             }
           )
           |> resolve
         )
    );

    Some(() => ());
  });

  let handleResize =
    React.useCallback(l =>
      switch (resizeWidgetId) {
      | Some((_, height, width)) =>
        if (height !== hGet(l) || width !== wGet(l)) {
          setResizeWidgetId(_ => Some((iGet(l), hGet(l), wGet(l))));
        }
      | None => ()
      }
    );

  let handleRedraw =
    React.useCallback(id =>
      switch (resizeWidgetId) {
      | Some((wid, height, width)) =>
        wid == id ? Some((height, width)) : None
      | None => None
      }
    );

  <GridContainer>
    <GridLayout.Responsive
      className="layout"
      layouts={generateLayout(widgets)}
      breakpoints
      cols
      rowHeight=80
      width
      onResize={(_, _, l) => handleResize(l)}>
      {
        React.array(
          Array.map(
            w =>
              <div key={w.id} id={w.id} className=widget>
                {
                  w.config
                  |> JSONfn.parse
                  |> (
                    config =>
                      switch (config) {
                      | None =>
                        <div key={w.id}> {"error" |> React.string} </div>
                      | Some(options) =>
                        <EChart options redraw={handleRedraw(w.id)} />
                      }
                  )
                }
              </div>,
            widgets,
          ),
        )
      }
    </GridLayout.Responsive>
  </GridContainer>;
};