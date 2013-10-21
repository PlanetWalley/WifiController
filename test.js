var exec = require('child_process').exec,
    child;

child = exec('ConsoleCursor.exe 1 12 12',
  function (error, stdout, stderr) {
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + stderr);
    if (error !== null) {
      console.log('exec error: ' + error);
    }
});