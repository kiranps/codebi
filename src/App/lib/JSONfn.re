[@bs.val] external eval: string => Chart.Chart.options = "eval";

let parse = str =>
  try (Some(eval("(" ++ str ++ ")"))) {
  | Js.Exn.Error(e) =>
    Js.log(e);
    None;
  };