open Css;
Utils.require("react-grid-layout/css/styles.css");

let layouts = [%raw
  {|
    {
     lg: [
      {i: 'a', x: 0, y: 0, w: 4, h: 3},
      {i: 'b', x: 4, y: 0, w: 4, h: 3},
      {i: 'c', x: 8, y: 0, w: 4, h: 3}
     ],
     md: [
      {i: 'a', x: 0, y: 0, w: 4, h: 3},
      {i: 'b', x: 4, y: 0, w: 4, h: 3},
      {i: 'c', x: 8, y: 0, w: 4, h: 3}
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

[@react.component]
let make = _ => {
  let width = Hooks.useWindowSize();

  <GridLayout.Responsive
    className="layout" layouts breakpoints cols rowHeight=30 width>
    <div key="a" className=widget> {React.string("a")} </div>
    <div key="b" className=widget> {React.string("b")} </div>
    <div key="c" className=widget> {React.string("c")} </div>
  </GridLayout.Responsive>;
};