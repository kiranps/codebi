let getWidget = id =>
  Js.Promise.(
    Http.get("/api/get-widget/?id=" ++ id)
    |> then_(json => Js.log(json) |> resolve)
  );