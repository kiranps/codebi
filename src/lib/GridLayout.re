type layout;
[@bs.module] [@react.component]
external make:
  (
    ~children: React.element,
    ~className: string=?,
    ~layout: array(layout)=?,
    ~cols: int=?,
    ~rowHeight: int=?,
    ~width: int=?
  ) =>
  React.element =
  "react-grid-layout";