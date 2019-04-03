let component = ReasonReact.statelessComponent("PreviewContainer");

let make = children => {
  ...component,
  render: _self => <div className=Styles.preview_container> ...children </div>,
};