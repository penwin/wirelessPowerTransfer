var server = require("./server");
var router = require("./route");
var requestHandlers = require("./requestHandlers");

var debug = false;

var handle = {}
handle["/"] = requestHandlers.sendInterface;
handle["/interface"] = requestHandlers.sendInterface;
handle["/client/js/app.js"] = requestHandlers.sendJavascript;
handle["/client/css/main.css"] = requestHandlers.sendCSS;

server.start(router.route,handle,debug);