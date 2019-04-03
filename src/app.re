Utils.require("./app.css");

[@bs.module] external logo: string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <AppContext.Provider>
      <EditorContainer> <EditorC /> </EditorContainer>
      <PreviewContainer>
        <AppContext.Consumer>
          ...{text => ReasonReact.string(text.state.code)}
        </AppContext.Consumer>
      </PreviewContainer>
    </AppContext.Provider>,
};