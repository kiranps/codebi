open Widget.Types;

let openPlayground = id => "#/playground/" ++ id |> ReasonReactRouter.push;

[@react.component]
let make = _ => {
  let (widgets, _) = Widget.useWidget();

  React.useEffect0(() => {
    Widget.Api.fetchAll();
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
          widget => <div key={widget.id}> {React.string(widget.name)} </div>,
          widgets,
        ),
      )
    }
    <Button onClick=handleCreate> {React.string("create widget")} </Button>
  </div>;
};