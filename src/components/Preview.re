[@react.component]
let make = () => {
  let (state, _) = AppContext.useApp();

  ReasonReact.string(state.code);
};