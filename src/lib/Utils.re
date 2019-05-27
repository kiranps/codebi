[@bs.val] external require: string => unit = "require";
[@bs.module] external uuid: unit => string = "uuid/v4";

let window = [%bs.raw {| window |}];

let windowInnerWidth = () => [%bs.raw {| window.innerWidth |}];

[@bs.send]
external addEvent: (Dom.window, string, unit => unit) => unit =
  "addEventListener";

[@bs.send]
external removeEvent: (Dom.window, string, unit => unit) => unit = "";