open Widget.Types;

let openPlayground = id => "#/playground/" ++ id |> ReasonReactRouter.push;

[@react.component]
let make = _ => {
  let (widgets, setWidgets) = React.useState(() => [||]);

  React.useEffect0(() => {
    Js.Promise.(
      Widget.Api.fetchAll()
      |> then_(json =>
           (
             switch (json) {
             | Widgets(data) => setWidgets(_ => data)
             | Failure => setWidgets(_ => [||])
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

  <div>
    {
      React.array(
        Array.map(
          widget =>
            <div>
              <span key={widget.id}> {React.string(widget.id)} </span>
              <a href={"#/playground/" ++ widget.id}>
                {"open" |> React.string}
              </a>
            </div>,
          widgets,
        ),
      )
    }
    <Button onClick=handleCreate> {React.string("create widget")} </Button>
  </div>;
};