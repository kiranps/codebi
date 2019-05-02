module Types = {
  type state = {code: string};
  type action =
    | Change(string);
};

module Context = {
  type t = {
    state: Types.state,
    dispatch: Types.action => unit,
  };
  include ReactContext.Make({
    type context = t;
    let defaultValue = {
      state: {
        code: "hello world kiran",
      },
      dispatch: _ => Js.log("nothing"),
    };
  });
};

module Provider = {
  include Types;
  [@react.component]
  let make = (~children) => {
    let (state, dispatch) =
      React.useReducer(
        (state, action) =>
          switch (action) {
          | Change(value) => {code: value}
          },
        {code: ""},
      );
    <Context.Provider value={state, dispatch}> children </Context.Provider>;
  };
};

let useApp = () => {
  let ctx = React.useContext(Context.x);
  Js.log(ctx);
  let save = value => ctx.dispatch(Change(value));
  (ctx.state, save);
};