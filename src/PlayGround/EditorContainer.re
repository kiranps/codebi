open Css;

let editor_container =
  style([
    position(absolute),
    display(inlineBlock),
    top(px(0)),
    bottom(px(0)),
    left(px(0)),
    width(pct(50.0)),
    boxSizing(borderBox),
    borderRight(px(1), solid, rgba(158, 158, 158, 0.41)),
  ]);

[@react.component]
let make = (~children) => <div className=editor_container> children </div>;