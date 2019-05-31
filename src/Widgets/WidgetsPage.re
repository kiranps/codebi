open Widget.Types;

[@react.component]
let make = _ => {
  let (widgets, _) = Widget.useWidget();

  React.useEffect0(() => {
    Http.get("/api/get-widgets");
    Some(() => ());
  });

  let handleCreate = _ => {
    Js.Promise.(Widget.create() |> then_(json => json |> Js.log |> resolve));
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