const { send, json } = require("micro");
const mongoose = require("mongoose");
const { Widget } = require("./model");

mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  const { id, name, config } = await json(req);
  try {
    const widget = await Widget.updateOne({ _id: id }, { name, config }).exec();
    send(res, 200, { status: "success" });
  } catch (error) {
    send(res, 200, { status: "error" });
  }
};
