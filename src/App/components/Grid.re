open Css;
open Widget.Types;
open GridLayout.Types;

Utils.require("react-grid-layout/css/styles.css");

let layouts = [%raw
  {|
    {
     lg: [
      {i: 'a', x: 0, y: 0, w: 4, h: 4},
      {i: 'b', x: 4, y: 0, w: 4, h: 4},
      {i: 'c', x: 8, y: 0, w: 4, h: 4}
     ]
    }
  |}
];

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

/* w: 4,
   h: 9,
   x: (i % 3) * 4,
   y: Math.floor((i / 3) * 3),
   i: widget.id.toString() */

let createLayouts = x => gridLayout(~lg=x);

let generateLayout = arr =>
  arr
  |> Array.mapi((i, widget) =>
       layout(~w=4, ~h=4, ~x=i mod 3 * 4, ~y=i / 3 * 3, ~i=widget.id)
     )
  |> createLayouts;

[@react.component]
let make = _ => {
  let (widgets, setWidgets) = React.useState(() => [||]);
  let width = Hooks.useWindowSize();

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

  <GridLayout.Responsive
    className="layout"
    layouts={generateLayout(widgets)}
    breakpoints
    cols
    rowHeight=80
    width>
    {
      React.array(
        Array.map(
          w =>
            <div key={w.id} className=widget>
              {
                w.config
                |> JSONfn.parse
                |> (
                  config =>
                    switch (config) {
                    | None => "error" |> React.string
                    | Some(options) => <Chart options />
                    }
                )
              }
            </div>,
          widgets,
        ),
      )
    }
  </GridLayout.Responsive>;
};