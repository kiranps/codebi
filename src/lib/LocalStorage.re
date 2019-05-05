let getItem = db => {
  let store = Dom.Storage.(localStorage |> getItem(db));
  store;
};

let setItem = (db, value) => {
  let store = Dom.Storage.(localStorage |> setItem(db, value));
  store;
};

let removeItem = db => Dom.Storage.(localStorage |> removeItem(db));