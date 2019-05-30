let postWidget = () => {
  let payload = Js.Dict.empty();
  Js.Dict.set(payload, "hello", Js.Json.string("world"));
  let data = payload |> Js.Json.object_;

  Js.Promise.(
    Http.post("/api/create-widgets", data)
    |> then_(json => Js.log(json) |> resolve)
  );
};

let getWidgets = () =>
  Js.Promise.(
    Http.get("/api/get-widgets") |> then_(json => Js.log(json) |> resolve)
  );

let getWidget = id =>
  Js.Promise.(
    Http.get("/api/get-widget/" ++ string_of_int(id))
    |> then_(json => Js.log(json) |> resolve)
  );