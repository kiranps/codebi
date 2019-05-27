let useWindowSize = () => {
  let (width, setWidth) = React.useState(() => Utils.windowInnerWidth());

  React.useEffect0(() => {
    let handleResize = () => setWidth(Utils.windowInnerWidth());
    Utils.addEvent(Utils.window, "resize", handleResize);

    Some(() => Utils.removeEvent(Utils.window, "resize", handleResize));
  });

  width;
};