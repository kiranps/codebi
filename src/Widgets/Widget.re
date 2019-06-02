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

  type widgetResponse =
    | Widget(widgetType)
    | NotFound
    | Failure;

  type widgetResponse0 = {
    status: string,
    message: string,
  };

  type widgetResponse1 = {
    status: string,
    widget: widgetType,
  };

  type widgetResponse2 = {status: string};

  type widgetResponse3 = {
    status: string,
    widget: widgetType,
    message: string,
  };
};

module Decode = {
  open Types;

  let object_ = json =>
    Json.Decode.{
      id: json |> field("id", string),
      name: json |> field("name", string),
      config: json |> field("config", string),
    };

  let objectArray = Json.Decode.array(object_);

  let status = json => json |> Json.Decode.(field("status", string));

  let widget = json => json |> Json.Decode.(field("widget", object_));
};

module Encode = {
  open Types;

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

module Api = {
  open Types;

  let save = data => {
    let payload = data |> Encode.object_;

    Js.Promise.(Http.post("/api/update-widget", payload));
  };

  let create = _ => {
    open Types;
    let payload =
      Json.Encode.(
        object_([("name", string("")), ("config", string(""))])
      );

    Js.Promise.(
      Http.post("/api/create-widget", payload)
      |> then_(json => json |> Decode.object_ |> resolve)
    );
  };

  let fetchAll = () => Http.get("/api/get-widgets");

  let fetch = id =>
    Js.Promise.(
      Http.get("/api/get-widget/?id=" ++ id)
      |> then_(json =>
           switch (Decode.status(json)) {
           | "found" =>
             json |> Decode.widget |> (json => Widget(json) |> resolve)
           | "not_found" => NotFound |> resolve
           | _ => Failure |> resolve
           }
         )
    );
};

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