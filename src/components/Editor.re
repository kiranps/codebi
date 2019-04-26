module Editor = {
  open Types;

  Utils.require("codemirror/keymap/vim");
  Utils.require("codemirror/lib/codemirror.css");
  Utils.require("codemirror/addon/dialog/dialog.css");

  type state = {
    editor: ref(option(Dom.element)),
    code: string,
  };

  type action =
    | ChangeInput(string);

  let component = ReasonReact.reducerComponent("Editor");

  let make = (~dispatch, _children) => {
    let setEditorRef = (theRef, self) =>
      self.ReasonReact.state.editor := Js.Nullable.toOption(theRef);
    {
      ...component,
      initialState: () => {code: "", editor: ref(None)},
      reducer: (action, state) =>
        switch (action) {
        | ChangeInput(value) => ReasonReact.Update({...state, code: value})
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
        Codemirror.on(
          cm,
          "change",
          e => {
            let value = Codemirror.getValue(e);
            Js.log(value);
            dispatch(Change(value));
          },
        );
      },
      render: self =>
        <div ref={self.handle(setEditorRef)} className=Styles.editor />,
    };
  };
};

let component = ReasonReact.statelessComponent("Container");
let make = _children => {
  ...component,
  render: _self =>
    <AppContext.Consumer>
      ...{({dispatch}) => <Editor dispatch />}
    </AppContext.Consumer>,
};