function solution(answers) {
  var answer = [];

  const s1 = [1, 2, 3, 4, 5];
  const s2 = [2, 1, 2, 3, 2, 4, 2, 5];
  const s3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  let s1Idx = 0;
  let s2Idx = 0;
  let s3Idx = 0;

  let s1Answer = 0;
  let s2Answer = 0;
  let s3Answer = 0;

  for (const number of answers) {
    if (s1[s1Idx] == number) s1Answer++;
    if (s2[s2Idx] == number) s2Answer++;
    if (s3[s3Idx] == number) s3Answer++;

    s1Idx++;
    s2Idx++;
    s3Idx++;

    s1Idx %= s1.length;
    s2Idx %= s2.length;
    s3Idx %= s3.length;
  }

  const maxAnswer = Math.max(s1Answer, s2Answer, s3Answer);

  if (s1Answer === maxAnswer) answer.push(1);
  if (s2Answer === maxAnswer) answer.push(2);
  if (s3Answer === maxAnswer) answer.push(3);

  return answer;
}
