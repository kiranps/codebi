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

[@react.component]
let make = _ => {
  let width = Hooks.useWindowSize();

  <GridLayout.Responsive
    className="layout" layouts breakpoints cols rowHeight=30 width>
    <div key="a" className=Styles.widget> {React.string("a")} </div>
    <div key="b" className=Styles.widget> {React.string("b")} </div>
    <div key="c" className=Styles.widget> {React.string("c")} </div>
  </GridLayout.Responsive>;
};