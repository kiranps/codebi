type ctx = option(Dom.element);
type options;
type chart;

[@bs.new] [@bs.module] external chartjs: (ctx, options) => chart = "chart.js";

[@react.component]
let make = (~options) => {
  let divRef = React.useRef(Js.Nullable.null);

  React.useEffect1(
    () => {
      let _ =
        chartjs(Js.Nullable.toOption(React.Ref.(current(divRef))), options);
      Some(() => ());
    },
    [||],
  );

  <canvas ref={ReactDOMRe.Ref.domRef(divRef)} width="400" height="400" />;
};