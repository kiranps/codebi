open Widgets.Types;

let toWidgetDict = widget => {
  let dict = Js.Dict.empty();
  Js.Dict.set(dict, "id", Js.Json.string(widget.id));
  Js.Dict.set(dict, "name", Js.Json.string(widget.name));
  Js.Dict.set(dict, "config", Js.Json.string(widget.config));
  dict;
};

let getWidgets = () =>
  switch (LocalStorage.getItem("widgets")) {
  | None => [||]
  | Some(value) =>
    let widgets = value |> Json.parseOrRaise |> Widgets.Decode.widgets;
    widgets;
  };

let appendWidget = widget => {
  let widgets = getWidgets() |> Array.map(toWidgetDict);
  Array.append(widgets, [|widget|]);
};

let stringifyJsonArray = json =>
  Js.Json.stringify(Js.Json.objectArray(json));

let fetchOrCreatewidget = id => {
  let data = {id, name: id, config: ""};
  let str = data |> toWidgetDict |> appendWidget |> stringifyJsonArray;
  str;
};

/*
  let widg = wid |> toJsWidget |> Array.append([||])
  let widg2 = widg |> Array.append(widg)
  let stringifyWidgets = (widgets) => Js.Json.stringify(Js.Json.objectArray(widgets))
 */

[@react.component]
let make = (~docId) => {
  let (_state, change) = AppContext.useApp();
  let (code, setCode) = React.useState(() => None);

  React.useEffect0(() => {
    /* Api.fetchWidgets(); */

    let code =
      switch (docId |> LocalStorage.getItem) {
      | None => ""
      | Some(value) => value
      };

    change(code);
    setCode(_ => Some(code));
    Some(() => ());
  });

  let handleSave =
    React.useCallback0(value => {
      LocalStorage.setItem(docId, value);
      change(value);
    });

  switch (code) {
  | None => <Loading />
  | Some(value) => <CodeMirror value onSave=handleSave />
  };
};