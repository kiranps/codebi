type t;

[@bs.val] external eval: string => string = "eval";

let parse = str => eval("(" ++ str ++ ")");