module Types = {
  type widgetType = {
    id: string,
    name: string,
    config: string,
  };

  type newWidget = {
    name: string,
    config: string,
  };
};

module Decode = {
  include Types;
  let object_ = json =>
    Json.Decode.{
      id: json |> field("id", string),
      name: json |> field("name", string),
      config: json |> field("config", string),
    };

  let objectArray = Json.Decode.array(object_);
};

module Encode = {
  include Types;
  let object_ = widget =>
    Json.Encode.(
      object_([
        ("id", string(widget.id)),
        ("name", string(widget.name)),
        ("config", string(widget.config)),
      ])
    );

  let objectArray = x => x |> Array.map(object_) |> Json.Encode.jsonArray;
};

let save = data => {
  let payload = data |> Encode.object_;

  Js.Promise.(Http.post("/api/update-widget", payload));
};

let create = _ => {
  open Types;
  let payload =
    Json.Encode.(object_([("name", string("")), ("config", string(""))]));

  Http.post("/api/create-widget", payload);
};

let fetchWidgets = () => Http.get("/api/get-widgets");

let useWidget = () => {
  let (widgets, setWidget) = React.useState(() => [||]);

  React.useEffect0(() => {
    let widgets =
      switch (LocalStorage.getItem("widgets")) {
      | None => [||]
      | Some(value) =>
        let widgets = value |> Json.parseOrRaise |> Decode.objectArray;
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