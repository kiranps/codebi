const { send, json } = require("micro");

module.exports = async (req, res) => {
  const data = await json(req);
  send(res, 201, { message: "hello world" });
};
