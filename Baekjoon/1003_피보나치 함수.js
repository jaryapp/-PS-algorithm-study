"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var count = (function () {
    function count() {
    }
    return count;
}());
var dp = new Array();
function fibonacci(n) {
    var result = new count();
    if (n == 0) {
        result.zero = 1;
        result.one = 0;
    }
    else if (n == 1) {
        result.zero = 0;
        result.one = 1;
    }
    else if (typeof dp[n] != 'undefined') {
        result = dp[n];
    }
    else {
        var before = fibonacci(n - 1);
        var moreBefore = fibonacci(n - 2);
        result.one = before.one + moreBefore.one;
        result.zero = before.zero + moreBefore.zero;
        dp[n] = result;
    }
    return result;
}
function main() {
    var num = new Array();
    for (var i = 0; i < input.length; i++) {
        num[i] = parseInt(input[i]);
    }
    var cnt = num[0];
    for (var i = 1; i < num.length; i++) {
        var result = fibonacci(num[i]);
        console.log(result.zero + " " + result.one);
    }
}
main();
