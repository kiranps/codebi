[@react.component]
let make = () => {
  let hash = ReasonReactRouter.useUrl().hash;
  let path = Js.String.split("/", hash);

  switch (path) {
  | [|"", "widgets"|] => <ListWidgets />
  | [|"", "dashboards"|] => <Dashboards />
  | [|"", "grid"|] => <Grid />
  | [|"", "editor", docId|] => <PlayGround docId />
  | _ => <NotFound />
  };
};