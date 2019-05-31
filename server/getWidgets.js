const { send, json } = require("micro");
const mongoose = require("mongoose");
const { Widget } = require("./model");

mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  Widget.find({}, (err, widgets) => {
    if (err) {
      send(res, 201, { status: "error" });
    } else {
      send(
        res,
        201,
        widgets.map(x => ({ id: x.id, name: x.name, config: x.config }))
      );
    }
  });
};
