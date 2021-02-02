function solution(numbers) {
  var answers = [];
  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      const sum = numbers[i] + numbers[j];
      if (!answers.includes(sum)) answers.push(sum);
    }
  }

  return answers.sort((a, b) => a - b);
}
