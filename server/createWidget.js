// const { send, json } = require("micro");
const mongoose = require("mongoose");
mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

const Widget = mongoose.model("Widget", {
  id: String,
  name: String,
  config: String
});

module.exports = async (req, res) => {
  const data = await json(req);
  const widget = new Widget(data);
  widget.save().then(() => console.log("meow"));
  send(res, 201, { message: "hello world" });
};
