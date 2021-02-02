function solution(participant, completion) {
  var answer = "";
  let count = {};

  for (const name of completion) {
    if (count[name] === undefined) {
      count[name] = 1;
    } else count[name]++;
  }

  for (const name of participant) {
    if (count[name] === undefined || count[name] === 0) {
      return name;
    } else count[name]--;
  }
}
