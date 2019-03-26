[@bs.deriving abstract]
type cmprops = {
  lineNumbers: bool,
  value: string,
  keyMap: string
};

type cmd;
type e;
type sv = {. [@bs.set] "save": e  => unit };

[@bs.module] external codemirror: (option(Dom.element), cmprops) => unit = "codemirror";
[@bs.module "codemirror"] external commands: sv = "";
[@bs.send] external getValue: (e) => string = "";

commands##save #= ((e) => {
  Js.log(getValue(e))
})

Utils.require("codemirror/lib/codemirror.css");
Utils.require("codemirror/addon/dialog/dialog.css");
Utils.require("codemirror/keymap/vim");

type state = {
  editor: ref(option(Dom.element)),
  code: string,
};

type action =
  | Change(string);

let component = ReasonReact.reducerComponent("Editor");

let make = _children => {
  let setEditorRef = (theRef, self) => {
    self.ReasonReact.state.editor := Js.Nullable.toOption(theRef);
  };
  {
    ...component,
    initialState: () => {code: "", editor: ref(None)},
    reducer: (action, state) =>
      switch (action) {
      | Change(value) => ReasonReact.Update({...state, code: value})
      },
    didMount: self => {
      let options = cmprops(~lineNumbers=true, ~value="hello world", ~keyMap="vim")
      codemirror(self.ReasonReact.state.editor^, options) 
      Js.log("hello")
    },
    render: self =>
      <div ref={self.handle(setEditorRef)} className=Styles.editor />,
  };
};