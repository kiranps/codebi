open Widgets.Types;

[@react.component]
let make = _ => {
  let (widgets, _) = Widgets.useWidget();

  Js.log("hello world");

  <div>
    {
      React.array(
        Array.map(
          widget => <div key={widget.id}> {React.string(widget.name)} </div>,
          widgets,
        ),
      )
    }
  </div>;
};