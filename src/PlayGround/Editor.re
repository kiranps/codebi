open Widget.Types;
type codeState =
  | NotFound
  | Error
  | Config(string)
  | Loading;

[@react.component]
let make = (~docId) => {
  let (_state, change) = PlayGroundContext.useApp();
  let (code, setCode) = React.useState(() => Loading);

  React.useEffect0(() => {
    Js.Promise.(
      Widget.Api.fetch(docId)
      |> then_(json =>
           (
             switch (json) {
             | Widget(data) =>
               data
               |> (
                 widget => {
                   change(widget.config);
                   setCode(_ => Config(widget.config));
                 }
               )
             | NotFound => setCode(_ => NotFound)
             | Failure => setCode(_ => Error)
             }
           )
           |> resolve
         )
    );

    Some(() => ());
  });

  let handleSave =
    React.useCallback0(value => {
      let data = {id: docId, name: docId, config: value};
      Widget.Api.save(data);
      change(value);
    });

  switch (code) {
  | Loading => <Loading />
  | Config(value) => <CodeMirror value onSave=handleSave />
  | NotFound => <div> {"Not found" |> React.string} </div>
  | Error => <div> {"Error" |> React.string} </div>
  };
};