[@react.component]
let make = () => {
  let (_state, change) = AppContext.useApp();
  let (code, setCode) = React.useState(() => None);
  let route = ReasonReactRouter.useUrl().hash;
  let docId = String.sub(route, 8, 2);

  React.useEffect1(
    () => {
      let code =
        switch (LocalStorage.getItem(docId)) {
        | None => ""
        | Some(value) => value
        };
      change(code);
      setCode(_ => Some(code));
      Some(() => ());
    },
    [||],
  );

  let handleSave =
    React.useCallback1(
      value => {
        LocalStorage.setItem(docId, value);
        change(value);
      },
      [||],
    );

  switch (code) {
  | None => <Loading />
  | Some(value) => <CodeMirror value onSave=handleSave />
  };
};