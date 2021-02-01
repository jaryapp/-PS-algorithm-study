/**
 * @param {number} n
 * @return {string[]}
 */

function dfs(open, close, n, arr, answer) {
  if (open == n && close == n) {
    answer.push(arr.join(""));
    return;
  }

  if (open < n) {
    arr.push("(");
    dfs(open + 1, close, n, arr, answer);
    arr.pop();
  }
  if (close < open) {
    arr.push(")");
    dfs(open, close + 1, n, arr, answer);
    arr.pop();
  }
}

var generateParenthesis = function (n) {
  let answer = [];
  dfs(0, 0, n, [], answer);

  return answer;
};
