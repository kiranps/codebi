const mongoose = require("mongoose");

const Widget = mongoose.model("Widget", {
  name: String,
  config: String
});

module.exports = {
  Widget
};
