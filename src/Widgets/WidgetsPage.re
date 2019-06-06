open Widget.Types;

type actions =
  | Update(array(widgetType))
  | Delete(string);

type state = {widgets: array(widgetType)};

let openPlayground = id => "#/playground/" ++ id |> ReasonReactRouter.push;

[@react.component]
let make = _ => {
  let (widgets, setWidgets) = React.useState(() => [||]);

  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Update(value) => {widgets: value}
        | Delete(id) => {
            widgets: Belt.Array.keep(state.widgets, x => x.id !== id),
          }
        },
      {widgets: [||]},
    );

  React.useEffect0(() => {
    Js.Promise.(
      Widget.Api.fetchAll()
      |> then_(json =>
           (
             switch (json) {
             | Widgets(data) => dispatch(Update(data))
             | Failure => dispatch(Update([||]))
             }
           )
           |> resolve
         )
    );
    Some(() => ());
  });

  let handleCreate = _ => {
    Js.Promise.(
      Widget.Api.create()
      |> then_(json => json.id |> openPlayground |> resolve)
    );
    ();
  };

  let handleDelete = id => {
    Js.Promise.(
      Widget.Api.delete(id)
      |> then_(status =>
           (
             switch (status) {
             | Deleted(id) => dispatch(Delete(id))
             | _ => Js.log("error")
             }
           )
           |> resolve
         )
    );
    ();
  };

  <div>
    {
      React.array(
        Array.map(
          widget =>
            <div key={widget.id}>
              <span> {React.string(widget.id)} </span>
              <a href={"#/playground/" ++ widget.id}>
                {"open" |> React.string}
              </a>
              <button onClick={_ => handleDelete(widget.id)}>
                {"delete" |> React.string}
              </button>
            </div>,
          state.widgets,
        ),
      )
    }
    <Button onClick=handleCreate> {React.string("create widget")} </Button>
  </div>;
};