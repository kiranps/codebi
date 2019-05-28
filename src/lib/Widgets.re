module Types = {
  type widgetType = {
    id: string,
    name: string,
    config: string,
  };
};

module Decode = {
  include Types;
  let widget = json =>
    Json.Decode.{
      id: json |> field("id", string),
      name: json |> field("name", string),
      config: json |> field("config", string),
    };

  let widgets = Json.Decode.array(widget);
};

let useWidget = () => {
  let (widgets, setWidget) = React.useState(() => [||]);

  React.useEffect0(() => {
    let widgets =
      switch (LocalStorage.getItem("widgets")) {
      | None => [||]
      | Some(value) =>
        let widgets = value |> Json.parseOrRaise |> Decode.widgets;
        widgets;
      };

    setWidget(_ => widgets);
    Some(() => ());
  });

  let getWidget = id => {
    open Types;

    let listOfWidget = widgets |> Array.to_list;

    switch (List.find(widget => widget.id == id, listOfWidget)) {
    | item => Some(item)
    | exception Not_found => None
    };
  };

  (widgets, getWidget);
};