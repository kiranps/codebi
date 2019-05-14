const React = require("react");
const createReactClass = require("create-react-class");

const ErrorBoundary = createReactClass({
  getInitialState: function() {
    return { hasError: false };
  },
  statics: {
    getDerivedStateFromError: function(error) {
      return { hasError: true };
    }
  },
  refresh: function() {
    this.setState({ hasError: false });
  },
  componentDidCatch: function() {},
  render: function() {
    if (this.state.hasError) {
      return React.createElement("div", null, "something went wrong");
    }

    return this.props.children;
  }
});

module.exports.default = ErrorBoundary;
