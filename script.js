const {exec} = require('child_process');

(async function(){
    const {stdout, stderr} = await exec('g++ sample.cpp && ./a.out');
    console.log(`stdout:${JSON.stringify(stdout)}`);
    console.log(`stderr:${JSON.stringify(stderr)}`);
})();
