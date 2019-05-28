let getItem = db => Dom.Storage.(localStorage |> getItem(db));

let setItem = (db, value) =>
  Dom.Storage.(localStorage |> setItem(db, value));

let removeItem = db => Dom.Storage.(localStorage |> removeItem(db));