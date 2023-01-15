const http = require("http");

const requestListener = function (req, res) {
	res.writeHead(200);
	res.end('hello from the other side');
};

const server = http.createServer(requestListener);
server.listen(8080);
