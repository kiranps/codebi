module EChart = {
  type ctx = option(Dom.element);
  type options;
  type chart;
  type echarts;

  [@bs.send] external init: (echarts, ctx) => chart = "";
  [@bs.send] external setOption: (chart, options) => unit = "";
  [@bs.send] external resize: chart => unit = "";
  [@bs.module] external echarts: echarts = "echarts";

  [@react.component]
  let make = (~options, ~redraw=false) => {
    let divRef = React.useRef(Js.Nullable.null);
    let myChart = React.useRef(true);

    React.useEffect1(
      () => {
        let dom = Js.Nullable.toOption(React.Ref.(current(divRef)));
        let plot = init(echarts, dom);
        Js.log(plot);
        Js.log(myChart);
        let _ = setOption(plot, options);
        Utils.addEvent(Utils.window, "resize", _ => resize(plot));
        Some(() => ());
      },
      [|options|],
    );

    React.useEffect1(
      () => {
        Js.log(redraw);
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
let make = (~options) => <ErrorBoundary> <EChart options /> </ErrorBoundary>;