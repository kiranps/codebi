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
    const widget = await Widget.findOne({ _id: id }).exec();
    if (widget) {
      const data = { id: widget._id, name: widget.name, config: widget.config };
      micro.send(res, 200, { status: "found", widget: data });
    } else {
      micro.send(res, 200, { status: "notfound" });
    }
  } catch (error) {
    micro.send(res, 200, { status: "error" });
  }
};

const qs = req => querystring.parse(url.parse(req.url).query);
