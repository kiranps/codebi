[@bs.module] external codemirror: option(Dom.element) => unit = "codemirror";
Utils.require("codemirror/lib/codemirror.css")

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
      codemirror(self.ReasonReact.state.editor^);
      Js.log("hello");
    },
    render: self => <div ref={self.handle(setEditorRef)} className=Styles.editor />,
  };
};