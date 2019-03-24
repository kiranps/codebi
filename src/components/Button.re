let component = ReasonReact.statelessComponent("Button")

let make = (~value, _children) => {
    ...component,
    render: _self => <button className=Styles.button>(ReasonReact.string(value))</button>
}