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

  type foo;
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