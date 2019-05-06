/* let options = [%bs.raw
     {|

        {
          type: 'line',
          data: {
              labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],
              datasets: [{
                  label: 'My First dataset',
                  backgroundColor: 'rgb(255, 99, 132)',
                  borderColor: 'rgb(255, 99, 132)',
                  data: [0, 10, 5, 2, 20, 30, 45]
              }]
          },
          options: {}
      }

      |}
   ]; */

[@react.component]
let make = () => {
  let (state, _) = AppContext.useApp();

  let result = JSONfn.parse(state.code);

  switch (result) {
  | None => <div> {"error" |> ReasonReact.string} </div>
  | Some(value) => <ErrorBoundary> <Chart options=value /> </ErrorBoundary>
  };
};

/* try (JSONfn.parse(state.code)) {
   | Js.Exn.Error(e) =>
     switch (Js.Exn.message(e)) {
     | Some(message) => message
     | None => "An unknown error occurred"
     }
   }; */