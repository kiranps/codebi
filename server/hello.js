const micro = require("micro");

module.exports = (req, res) => {
  micro.send(res, 200, "hello world");
};
