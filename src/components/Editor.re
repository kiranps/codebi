Utils.require("codemirror/keymap/vim");
Utils.require("codemirror/lib/codemirror.css");
Utils.require("codemirror/addon/dialog/dialog.css");

[@react.component]
let make = () => {
  let divRef = React.useRef(Js.Nullable.null);
  let (_state, change) = AppContext.useApp();

  React.useEffect1(
    () => {
      let options =
        Codemirror.cmprops(
          ~lineNumbers=true,
          ~value="hello world",
          ~keyMap="vim",
        );

      let cm =
        Codemirror.init(
          Js.Nullable.toOption(React.Ref.(current(divRef))),
          options,
        );
      Codemirror.commands##save #= (e => Js.log(Codemirror.getValue(e)));
      Codemirror.on(
        cm,
        "change",
        e => {
          let value = Codemirror.getValue(e);
          Js.log(value);
          change(value);
        },
      );

      Some(() => Js.log("unmount"));
    },
    [|true|],
  );

  <div className=Styles.editor ref={ReactDOMRe.Ref.domRef(divRef)} />;
};