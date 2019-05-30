// const { send, json } = require("micro");
const mongoose = require("mongoose");
mongoose.connect("mongodb://localhost:27017/test", { useNewUrlParser: true });

const Cat = mongoose.model("Cat", { name: String });

const kitty = new Cat({ name: "Zildjian" });
kitty.save().then(() => console.log("meow"));

module.exports = async (req, res) => {
  const data = await json(req);
  console.log(data);
  send(res, 201, { message: "hello world" });
};
