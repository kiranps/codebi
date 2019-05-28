/* Js.Promise.(
     Fetch.fetch("/api/hello")
     |> then_(Fetch.Response.json)
     |> then_(json => Js.log(json) |> resolve)
   ); */

module Http = {
  let post = (url, data) => {
    let contentType = {"Content-Type": "application/json"};
    let method_ = Fetch.Post;
    let headers = Fetch.HeadersInit.make(contentType);
    let body = Fetch.BodyInit.make(data);

    Fetch.fetchWithInit(
      url,
      Fetch.RequestInit.make(~method_, ~body, ~headers, ()),
    );
  };
};

let fetchWidgets = () => {
  let payload = Js.Dict.empty();
  Js.Dict.set(payload, "hello", Js.Json.string("world"));
  let data = Js.Json.stringify(Js.Json.object_(payload));

  Js.Promise.(
    Http.post("/api/hello", data)
    |> then_(Fetch.Response.json)
    |> then_(json => Js.log(json) |> resolve)
  );
};