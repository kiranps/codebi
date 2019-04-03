open Types;

// type state = {code: string};

// type action =
//   | Change(string)
//   | None;

// type providerType = {
//   state,
//   dispatch: action => unit,
// };

module AppContext =
  Context.MakePair({
    type t = providerType;
    let defaultValue = {
      state: {
        code: "",
      },
      dispatch: _ => Js.log("nothing"),
    };
  });

// module AppContext =
//   Context.MakePair({
//     type t = string;
//     let defaultValue = "hello world";
//   });

module Provider = {
  let component = ReasonReact.reducerComponent("AppProvider");

  let make = (~children) => {
    {
      ...component,
      initialState: () => {code: "hello man"},
      reducer: (action, state) =>
        switch (action) {
        | Change(value) => ReasonReact.Update({...state, code: value})
        },
      render: self =>
        // <AppContext.Provider value="hello world">
        <AppContext.Provider value={state: self.state, dispatch: self.send}>
          ...children
        </AppContext.Provider>,
    };
  };
};

module Consumer = AppContext.Consumer;