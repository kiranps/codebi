const micro = require("micro");
const url = require("url");
const mongoose = require("mongoose");
const querystring = require("querystring");
const { Widget } = require("./model");

mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  const { id } = qs(req);
  try {
    const widget = await Widget.deleteOne({ _id: id }).exec();
    if (widget) {
      micro.send(res, 200, { status: "deleted" });
    } else {
      micro.send(res, 200, { status: "notfound" });
    }
  } catch (error) {
    micro.send(res, 200, { status: "error" });
  }
};

const qs = req => querystring.parse(url.parse(req.url).query);
