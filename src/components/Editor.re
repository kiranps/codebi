Utils.require("codemirror/keymap/vim");
Utils.require("codemirror/lib/codemirror.css");
Utils.require("codemirror/addon/dialog/dialog.css");

type state = {
  editor: ref(option(Dom.element)),
  code: string,
};

type action =
  | Change(string);

let component = ReasonReact.reducerComponent("Editor");

let make = _children => {
  let setEditorRef = (theRef, self) =>
    self.ReasonReact.state.editor := Js.Nullable.toOption(theRef);
  {
    ...component,
    initialState: () => {code: "", editor: ref(None)},
    reducer: (action, state) =>
      switch (action) {
      | Change(value) => ReasonReact.Update({...state, code: value})
      },
    didMount: self => {
      let options =
        Codemirror.cmprops(
          ~lineNumbers=true,
          ~value="hello world",
          ~keyMap="vim",
        );
      let cm = Codemirror.init(self.ReasonReact.state.editor^, options);
      Codemirror.commands##save #= (e => Js.log(Codemirror.getValue(e)));
      Codemirror.on(cm, "change", e => Js.log(Codemirror.getValue(e)));
    },
    render: self =>
      <div ref={self.handle(setEditorRef)} className=Styles.editor />,
  };
};