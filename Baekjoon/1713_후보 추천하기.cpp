#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void) {

	int N, student;
	int vote[1002] = { 0, };
	// 1. 학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
	int arr[22] = { 0, };
	int cnt = 0;

	scanf("%d %d", &N, &student);

	for (int i = 0; i < student; i++) {
		int num;
		scanf("%d", &num);
		// 4. 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
		if (vote[num]) vote[num]++;
		else if (cnt < N) {
			// 2. 어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
			arr[cnt] = num;
			vote[num] = 1;
			cnt++;
		}
		else {
			int mn = vote[arr[0]];
			int idx = 0;
			for (int k = 0; k < N; k++) {
				if (mn > vote[arr[k]]) {
					mn = vote[arr[k]];
					idx = k;
				}
			}

			// 5. 사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
			vote[arr[idx]] = 0;

			// 3. 비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고,
			// 이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다
			for (int k = idx; k < N-1; k++) {
				arr[k] = arr[k + 1];
			}

			// 그 자리에 새롭게 추천받은 학생의 사진을 게시한다. 
			arr[N - 1] = num;
			vote[num] = 1;

		}
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) if(arr[i]) printf("%d ", arr[i]);

	return 0;
}