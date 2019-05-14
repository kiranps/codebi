[@react.component]
let make = () => {
  let (state, _) = AppContext.useApp();

  let result = JSONfn.parse(state.code);
  Js.log(result);

  switch (result) {
  | None => <div> {"error" |> ReasonReact.string} </div>
  | Some(value) => <Chart options=value />
  };
};