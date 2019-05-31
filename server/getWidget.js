const micro = require("micro");
const url = require("url");
const querystring = require("querystring");
const { Widget } = require("./model");

const mongoose = require("mongoose");
mongoose.connect("mongodb://localhost:27017/widgets", {
  useNewUrlParser: true
});

module.exports = async (req, res) => {
  const { id } = qs(req);
  console.log(id);
  Widget.findOne({ id }, (err, widget) => {
    if (err) {
      console.log(err);
      micro.send(res, 200, { status: "error" });
    } else {
      if (widget) {
      } else {
      }
      console.log(widget);
      micro.send(res, 200, widget);
    }
  });
};

const qs = req => querystring.parse(url.parse(req.url).query);
