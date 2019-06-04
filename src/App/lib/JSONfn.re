[@bs.val] external eval: string => EChart.EChart.options = "eval";

let parse = str =>
  try (Some(eval("(" ++ str ++ ")"))) {
  | Js.Exn.Error(e) =>
    Js.log(e);
    None;
  };