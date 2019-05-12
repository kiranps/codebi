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
  componentDidCatch: function() {},
  render: function() {
    if (this.state.hasError) {
      return "Something went wrong";
    }

    return this.props.children;
  }
});

module.exports.default = ErrorBoundary;
