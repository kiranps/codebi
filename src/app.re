Utils.require("./app.css")

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <Editorcontainer>
      <Editor/>
    </Editorcontainer>
};
