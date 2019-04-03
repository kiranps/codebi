[@bs.module "fs"] external writeFileSync : (string, string) => unit = "writeFileSync";

let component = "Hello"

let template = {j|
let component = ReasonReact.statelessComponent("$component")

let make = children => {
    ...component,
    render: _self => <div>...(children)</div>
}
|j};

Js.log(template)

writeFileSync("src/components/Styles/" ++ component ++ ".re", template);