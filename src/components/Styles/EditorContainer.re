let component = ReasonReact.statelessComponent("EditorContainer");

let make = children => {
  ...component,
  render: _self => <div className=Styles.editor_container> ...children </div>,
};