const { send, json } = require("micro");
const { Widget } = require("./model");
const mongoose = require("mongoose");

mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  const { id, name, config } = await json(req);
  const widget = await Widget.create({ id, name, config });
  const data = { id: widget.id, name: widget.name, config: widget.config };
  send(res, 200, data);
};
