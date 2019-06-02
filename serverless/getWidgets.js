const { send } = require("micro");
const mongoose = require("mongoose");
const { Widget } = require("./model");

mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  try {
    const widgets = await Widget.find({}).exec();
    send(res, 200, {
      status: "success",
      widgets: widgets.map(x => ({ id: x._id, name: x.name, config: x.config }))
    });
  } catch (error) {
    send(res, 200, { status: "error" });
  }
};
