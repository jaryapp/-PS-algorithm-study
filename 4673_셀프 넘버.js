"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var input;
try {
    input = fs.readFileSync('/dev/stdin').toString().split(/ |\n/);
}
catch (e) {
    input = fs.readFileSync('./dev/stdin').toString().split(/ |\n/);
}
function main() {
    var num = new Array();
    var rst = new Array(10001);
    for (var index in rst) {
        rst[index] = false;
    }
    for (var i = 0; i < 10001; i++) {
        var sum = i;
        for (var k = i; k != 0;) {
            sum += k % 10;
            k /= 10;
            k = parseInt(k);
        }
        // console.log(sum);
        rst[sum] = true;
    }
    for (var i = 0; i < 10001; i++) {
        if (!rst[i]) {
            console.log(i);
        }
    }
}
main();
