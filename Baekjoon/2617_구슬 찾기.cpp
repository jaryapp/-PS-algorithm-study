#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N, M;
int input[110][110] = { 0, };
bool visited[110] = { false, };

int bigOne(int target) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		if (input[target][i]) {
			visited[i] = true;
			cnt++;
			cnt += bigOne(i);
		}
	}
	return cnt;
}

int smallOne(int target) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		if (input[i][target]) {
			visited[i] = true;
			cnt++;
			cnt += smallOne(i);
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &N, &M);
	while (M) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		input[t1][t2] = true;
		M--;
	}
	int half = (N - 1) / 2 + 1;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		int bo = bigOne(i);
		memset(visited, 0, sizeof(visited));
		int so = smallOne(i);
		if (bo >= half || so >= half) answer++;
	}
	printf("%d", answer);
}