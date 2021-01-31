var threeSum = function (nums) {
  let answer = [];
  let count = {};
  nums.forEach((num) => {
    if (!count[num]) count[num] = 0;
    count[num]++;
  });

  let arr = Object.keys(count).sort();

  for (let i = 0; i < arr.length; i++) {
    let a = arr[i];
    count[a]--;
    for (let j = i; j < arr.length; j++) {
      let b = arr[j];
      if (count[b] == 0) continue;

      count[b]--;

      let c = -(parseInt(a) + parseInt(b));

      if (count[c] && c >= b) {
        answer.push([a, b, c]);
      }

      count[b]++;
    }

    count[a]++;
  }
  return answer;
};
