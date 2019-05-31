type layout;
[@bs.module] [@react.component]
external make:
  (
    ~children: React.element,
    ~className: string=?,
    ~layouts: array(layout)=?,
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
      ~layouts: array(layout)=?,
      ~breakpoints: breakpoints,
      ~cols: breakpoints,
      ~rowHeight: int=?,
      ~width: int=?
    ) =>
    React.element =
    "Responsive";
};