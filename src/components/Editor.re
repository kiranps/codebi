[@react.component]
let make = (~docId) => {
  let (_state, change) = AppContext.useApp();
  let (code, setCode) = React.useState(() => None);

  React.useEffect0(() => {
    Js.log(Utils.uuid());

    let code =
      switch (LocalStorage.getItem(docId)) {
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