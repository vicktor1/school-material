
const http = require('http');
const fs = require('fs');

function writeContent(res, fname) {
	try 
	{
		res.write(fs.readFileSync(fname, "utf-8"));
	}
	catch (err) 
	{
		console.error(err);
	}
}

function main() 
{
	const hostname = '127.0.0.1';
	const port = 3000;

	const server = http.createServer((req, res) => {
		if (req.method == "GET")
		{
			res.statusCode = 200;
			res.setHeader('Content-Type', 'text/html; charset=utf-8');

			switch (req.url)
			{
				case "/":
					writeContent(res, "index.html");
					res.end();
				break;

				case "/index.css":
					writeContent(res, "index.css");
					res.end();
				break;
			}
		}
		else
		{
			res.statusCode = 200;
			res.setHeader('Content-Type', 'text/html; charset=utf-8');

			res.end();
		}
	});

	server.listen(port, hostname, () => {
		console.log(`Server running at http://${hostname}:${port}/`);
	});
	//
}
main();
