Utils.require("./app.css");

[@bs.module] external logo: string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <AppContext.Provider>
      <EditorContainer> <Editor /> </EditorContainer>
      <PreviewContainer>
        <AppContext.Consumer>
          ...{({state}) => ReasonReact.string(state.code)}
        </AppContext.Consumer>
      </PreviewContainer>
    </AppContext.Provider>,
};