[@react.component]
let make = () => {
  let hash = ReasonReactRouter.useUrl().hash;
  let path = Js.String.split("/", hash);
  Js.log(path);

  switch (path) {
  | [|"", "widgets"|] => <Widgets />
  | [|"", "dashboards"|] => <Dashboards />
  | [|"", "editor", docId|] => <Builder docId />
  | _ => <NotFound />
  };
};