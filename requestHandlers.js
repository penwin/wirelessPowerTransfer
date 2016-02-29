// functions that will be executed when 
// typeoff handle[pathname] === a function in requestHandlers.
// the handle and function are discribed in index.js

var fs = require('fs'),
    server = require('./server');

function sendInterfaceImpl(response) {
  console.log("Request handler 'interface' was called.");
  response.writeHead(200, {"Content-Type": "text/html"});
  var html = fs.readFileSync(__dirname + "/client/interface.html")
  response.end(html);
}

function sendJavascriptImpl(response) {
  console.log("Request handler 'javascript' was called.");
  response.writeHead(200);
  var java = fs.readFileSync(__dirname + "/client/js/app.js")
  response.end(java);
}

function sendCSSImpl(response) {
  console.log("Request handler 'CSS' was called.");
  response.writeHead(200);
  var CSS = fs.readFileSync(__dirname + "/client/css/main.css")
  response.end(CSS);
}


exports.sendInterface = sendInterfaceImpl

exports.sendJavascript = sendJavascriptImpl

exports.sendCSS = sendCSSImpl