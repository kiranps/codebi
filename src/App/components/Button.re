open Css;

let btn =
  style([
    backgroundColor(white),
    borderColor(black),
    outlineStyle(none),
    cursor(`pointer),
  ]);

[@react.component]
let make = (~children, ~onClick) =>
  <button className=btn onClick> children </button>;