[@react.component]
let make = () => {
  let hash = ReasonReactRouter.useUrl().hash;
  let path = Js.String.split("/", hash);

  switch (path) {
  | [|"", "widgets"|] => <ListWidgets />
  | [|"", "dashboards"|] => <ListDashboards />
  | [|"", "grid"|] => <Grid />
  | [|"", "editor", docId|] => <Builder docId />
  | _ => <NotFound />
  };
};