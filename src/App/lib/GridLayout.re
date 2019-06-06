module Types = {
  [@bs.deriving abstract]
  type layout = {
    w: int,
    h: int,
    x: int,
    y: int,
    i: string,
  };

  [@bs.deriving abstract]
  type gridLayout = {lg: array(layout)};
};

open Types;

[@bs.module] [@react.component]
external make:
  (
    ~children: React.element,
    ~className: string=?,
    ~layouts: gridLayout=?,
    ~cols: int=?,
    ~rowHeight: int=?,
    ~width: int=?
  ) =>
  React.element =
  "react-grid-layout";

type breakpoints;
module Responsive = {
  [@bs.module "react-grid-layout"] [@react.component]
  external make:
    (
      ~children: React.element,
      ~className: string=?,
      ~layouts: gridLayout=?,
      ~breakpoints: breakpoints,
      ~cols: breakpoints,
      ~rowHeight: int=?,
      ~onResize: (array(layout), layout, layout) => unit,
      ~width: int=?
    ) =>
    React.element =
    "Responsive";
};

module Widget = {
  open Css;

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
  let make = (~children, ~id, ~className=?) =>
    <div key=id className=widget> children </div>;
};