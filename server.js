var http = require('http')
var exec = require('child_process').exec,
    child;
    
var fs = require('fs')
var server = http.createServer(function(req, res){
    fs.readFile('index.html',function (err, data){
        res.writeHead(200, {'Content-Type': 'text/html','Content-Length':data.length});
        res.write(data);
        //res.write("Hello World")
        res.end();
    });
}).listen(9000);

var io = require('socket.io').listen(server);
io.sockets.on('connection', function (socket) {
	console.log("Get Connection")
  console.log("usr : " + socket + " connects to server")
  socket.emit("user_connected","U have successfully connected")

  socket.on('mouse_move',function(data){
  	var x_c = data[0]
  	var y_c = data[1]
  	console.log("Server side :")
  	console.log("x :"+x_c+" y :"+y_c)

    // call ConsoleCursor.exe command
    child = exec('ConsoleCursor.exe 1 '+x_c+' '+y_c,
    function (error, stdout, stderr) {
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + stderr);
    if (error !== null) {
      console.log('exec error: ' + error);
    }
});
  })
});


