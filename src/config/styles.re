open Css;

let button =
  style([
    backgroundColor(red),
    display(inlineBlock),
    border(px(0), none, red),
    height(px(40)),
    width(px(100)),
    color(white),
  ]);

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

let editor =
  style([
    height(pct(100.0)),
    width(pct(100.0)),
    selector("& > div", [height(pct(100.0))]),
  ]);

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

/*
 box-shadow: 0 2px 5px 0 rgba(0, 0, 0, 0.1); */