[@bs.deriving abstract]
type cmprops = {
  lineNumbers: bool,
  value: string,
  mode: string,
  keyMap: string,
};

type cm;
type evt;
type cmds = {. [@bs.set] "save": evt => unit};

[@bs.module]
external init: (option(Dom.element), cmprops) => cm = "codemirror";
[@bs.module "codemirror"] external commands: cmds = "";
[@bs.send] external getValue: evt => string = "";
[@bs.send] external on: (cm, string, evt => unit) => unit = "";