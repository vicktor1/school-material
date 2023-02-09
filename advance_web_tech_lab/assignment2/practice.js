'use strict';
const http = require('http');
const fs = require('fs');
const querystring = require('querystring');



//create a server object:
http.createServer((req, res) => {
	if (req.method == 'GET')
	{
		res.setHeader("Content-Type", "text/html");
		switch (req.url) 
		{
			case "/":
			case "/index.html":
				res.writeHead(200);
				try 
				{
					res.write(fs.readFileSync('index.html', 'utf8'));  //write a response to the client
				} catch (err) {
					console.error(err);
					process.exit();
				}
				res.end(); 			// end the response
				break;
			
			default:
				res.write("404");
				res.end();
		}
	}
	else if (req.method == "POST")
	{
		if (req.url == "/submission") 
		{
			req.once("data", function(data) {
				let post;
				res.setHeader('Content-Type', 'text/html');
				res.writeHead(200);
				post = querystring.parse(data.toString());
				if (post.filename1)
				{
					if (post.task1 == "read")
					{
						try {
							res.write(`-----------------------------------${post.filename1}--------------------<br>`);
							res.write(`<html><body><pre>${fs.readFileSync(post.filename1, 'utf8')}</pre></body></html>`);  //write a response to the clieNt
						} catch (err) {
							console.error(err);
							process.exit();
						}					
					}
					
					if (post.task1 == "write")
					{
						try {
							res.write(`written text: "${post.data2write}" ${post.filename1}`);
							fs.writeFile(post.filename1, post.data2write, (err) => {
								if (err) throw err;
								res.write('The file has been saved');
							});
						} catch (err) {
							console.error(err);
							process.exit();
						}
					}
					if (post.task1 == "append")
					{
						try {
							res.write(`appended text: "${post.data2write}" ${post.filename2}`);
							fs.appendFile(post.filename1, post.data2write, (err) => {
								if (err) throw err;
								res.write('The data to append was append to file!');
							});
						}
						catch (err) {
							console.error(err);
						}
					}
					if (post.task1 == "delete")
					{
						fs.unlink(post.filename1, (err) => {
							if (err) throw err;
							res.write(`${post.filename1} was deleted`);
						})
					}
				}
				if (post.filename2)
				{
					if (post.task1 == "read")
					{
						try {
							res.write(`-----------------------------------${post.filename2}--------------------<br>`);
							res.write(`<html><body><pre>${fs.readFileSync(post.filename2, 'utf8')}</pre></body></html>`);  //write a response to the clieNt
						} catch (err) {
							console.error(err);
							process.exit();
						}					
					}
					else if (post.task1 == "write")
					{
						try {
							res.write(`written text: "${post.data2write}" ${post.filename2}`);
							fs.writeFile(post.filename2, post.data2write, (err) => {
								if (err) throw err;
								res.write('The file has been saved');
							});	
						} catch (err) {
							console.error(err);
							process.exit();
						}
					}
					if (post.task1 == "append")
					{
						try {
							res.write(`appended text: "${post.data2write}" ${post.filename2}`);
							fs.appendFile(post.filename2, post.data2write, (err) => {
								if (err) throw err;
								res.write('The data to append was append to file!');
							});
						}
						catch (err) {
							console.error(err);
						}
					}
					if (post.task1 == "delete")
					{
						fs.unlink(post.filename2, (err) => {
							if (err) throw err;
							res.write(`${post.filename2} was deleted`);
						});
					}
				}
				res.end();
			});
		}
	}
}).listen(8080); 			// the server object listens on port 8080
