[@react.component]
let make = (~docId) => {
  let (_state, change) = AppContext.useApp();
  let (code, setCode) = React.useState(() => None);

  React.useEffect1(
    () => {
      Js.log(Utils.uuid());

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