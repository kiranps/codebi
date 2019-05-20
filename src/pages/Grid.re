Utils.require("react-grid-layout/css/styles.css");

let layout = [%raw
  {|
   [
     {i: 'a', x: 0, y: 0, w: 1, h: 2, static: true},
     {i: 'b', x: 1, y: 0, w: 3, h: 2, minW: 2, maxW: 4},
     {i: 'c', x: 4, y: 0, w: 1, h: 2}
   ]
  |}
];

[@react.component]
let make = _ =>
  <GridLayout className="layout" layout cols=12 rowHeight=30 width=1200>
    <div key="a"> {React.string("a")} </div>
    <div key="b"> {React.string("b")} </div>
    <div key="c"> {React.string("c")} </div>
  </GridLayout>;