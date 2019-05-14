[@react.component]
let make = () => {
  let hash = ReasonReactRouter.useUrl().hash;
  let path = Js.String.split("/", hash);

  switch (path) {
  | [|"", "editor", docId|] => <Builder docId />
  | _ => <NotFound />
  };
};