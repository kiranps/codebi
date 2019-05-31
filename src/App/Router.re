[@react.component]
let make = () => {
  let hash = ReasonReactRouter.useUrl().hash;
  let path = Js.String.split("/", hash);

  switch (path) {
  | [|"", "widgets"|] => <WidgetsPage />
  | [|"", "dashboards"|] => <DashboardsPage />
  | [|"", "grid"|] => <Grid />
  | [|"", "editor", docId|] => <PlayGroundPage docId />
  | _ => <NotFoundPage />
  };
};