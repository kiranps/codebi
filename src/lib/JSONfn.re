[@bs.val] external eval: string => Chart.options = "eval";

let parse = str =>
  try (Some(eval("(" ++ str ++ ")"))) {
  | Js.Exn.Error(e) => None
  };