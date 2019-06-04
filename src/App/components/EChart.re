module EChart = {
  type ctx = option(Dom.element);
  type options;
  type chart;
  type echarts;

  [@bs.send] external init: (echarts, ctx) => chart = "";
  [@bs.send] external setOption: (chart, options) => unit = "";
  [@bs.send] external resize: Js.Nullable.t(chart) => unit = "";
  [@bs.module] external echarts: echarts = "echarts";

  [@react.component]
  let make = (~options, ~redraw) => {
    let divRef = React.useRef(Js.Nullable.null);
    let myChart = React.useRef(Js.Nullable.null);

    React.useEffect1(
      () => {
        let dom = Js.Nullable.toOption(React.Ref.(current(divRef)));
        let plot = init(echarts, dom);
        let _ = setOption(plot, options);
        React.Ref.(setCurrent(myChart, Js.Nullable.return(plot)));
        Some(() => ());
      },
      [|options|],
    );

    React.useEffect1(
      () => {
        switch (redraw) {
        | Some(value) =>
          let (height, width) = value;
          React.Ref.(current(myChart)) |> resize;
        | None => Js.log("none")
        };
        Some(() => ());
      },
      [|redraw|],
    );

    <div
      ref={ReactDOMRe.Ref.domRef(divRef)}
      style={ReactDOMRe.Style.make(~height="100%", ~width="100%", ())}
    />;
  };
};

[@react.component]
let make = (~options, ~redraw=?) =>
  <ErrorBoundary> <EChart options redraw /> </ErrorBoundary>;