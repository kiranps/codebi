type widgetType = {
  id: string,
  name: string,
  config: string,
};

module Decode = {
  let widget = json =>
    Json.Decode.{
      id: json |> field("id", string),
      name: json |> field("name", string),
      config: json |> field("config", string),
    };

  let widgets = Json.Decode.array(widget);
};

[@react.component]
let make = _ => {
  let widgets =
    switch (LocalStorage.getItem("widgets")) {
    | None => [||]
    | Some(value) =>
      let foo = value |> Json.parseOrRaise |> Decode.widgets;
      foo;
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
  </div>;
};