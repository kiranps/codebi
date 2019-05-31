open Css;

let preview_container =
  style([
    position(absolute),
    display(inlineBlock),
    top(px(0)),
    bottom(px(0)),
    right(px(0)),
    width(pct(50.0)),
    padding(px(15)),
    boxSizing(borderBox),
  ]);

[@react.component]
let make = (~children) => <div className=preview_container> children </div>;