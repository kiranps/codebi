[@react.component]
let make = () => {
  let (_state, change) = AppContext.useApp();
  let (code, setCode) = React.useState(() => "");
  let route = ReasonReactRouter.useUrl().hash;
  let docId = String.sub(route, 8, 2);

  Js.log("Editor");

  React.useEffect1(
    () => {
      let code =
        switch (LocalStorage.getItem(docId)) {
        | None => ""
        | Some(value) => value
        };
      change(code);
      setCode(_ => code);
      Some(() => ());
    },
    [|true|],
  );

  let handleSave =
    React.useCallback1(value => LocalStorage.setItem(docId, value), [||]);

  let handleChange = React.useCallback1(value => change(value), [||]);

  code === "" ?
    <Loading /> :
    <CodeMirror value=code onChange=handleChange onSave=handleSave />;
};