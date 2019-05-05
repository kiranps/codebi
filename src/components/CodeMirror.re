Utils.require("codemirror/keymap/vim");
Utils.require("codemirror/lib/codemirror.css");
Utils.require("codemirror/addon/dialog/dialog.css");

[@react.component]
let make =
  React.memo((~value, ~onChange=?, ~onSave=?) => {
    let divRef = React.useRef(Js.Nullable.null);
    Js.log("Codemirror");
    Js.log(value);

    React.useEffect1(
      () => {
        let options = CM.cmprops(~lineNumbers=true, ~keyMap="vim", ~value);

        let cm =
          CM.init(
            Js.Nullable.toOption(React.Ref.(current(divRef))),
            options,
          );

        switch (onSave) {
        | None => ()
        | Some(save) => CM.commands##save #= (e => save(CM.getValue(e)))
        };

        switch (onChange) {
        | None => ()
        | Some(change) =>
          CM.on(
            cm,
            "change",
            e => {
              let value = CM.getValue(e);
              change(value);
            },
          )
        };

        Some(() => ());
      },
      [|true|],
    );

    <div className=Styles.editor ref={ReactDOMRe.Ref.domRef(divRef)} />;
  });