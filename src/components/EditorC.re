let component = ReasonReact.statelessComponent("Container");
let make = _children => {
  ...component,
  render: _self =>
    <AppContext.Consumer>
      ...{ctx => <Editor dispatch={ctx.dispatch} />}
    </AppContext.Consumer>,
};