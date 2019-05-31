const { send, json } = require("micro");
const { Widget } = require("./model");
const mongoose = require("mongoose");

mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  const data = await json(req);
  const widget = new Widget(data);
  widget.save().then(widget => {
    const data = {
      id: widget._id,
      name: widget.name,
      config: widget.config
    };
    send(res, 201, data);
  });
};
