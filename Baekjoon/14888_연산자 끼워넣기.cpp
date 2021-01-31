#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

char turn[101];
vector<char> op;

bool visited[101];
int A[101];
int N;

int mx = INT_MIN;
int mn = INT_MAX;

int calc() {
	int total = A[0];
	for (int i = 1; i < N; i++) {
		char t = turn[i - 1];
		if (t == '+') total += A[i];
		if (t == '-') total -= A[i];
		if (t == '*') total *= A[i];
		if (t == '/') total /= A[i];
	}
	return total;
}

void dfs(int depth) {

	int tvisited[101] = { false, };
	if (depth == N-1) {
		int total = calc();
		mx = max(total, mx);
		mn = min(total, mn);

		return;
	}

	for (int i = 0; i < N-1; i++) {
		if (visited[i] || tvisited[op[i]]) continue;
		turn[depth] = op[i];
		visited[i] = true;
		tvisited[op[i]] = true;
		dfs(depth+1);
		visited[i] = false;
	}
}


int main(void) {
	

	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < 4; i++) {
		int cnt;
		scanf("%d", &cnt);
		while (cnt) {
			if (i == 0) op.push_back('+');
			if (i == 1) op.push_back('-');
			if (i == 2) op.push_back('*');
			if (i == 3) op.push_back('/');
			cnt--;
		}
	}

	dfs(0);

	printf("%d\n%d", mx, mn);

	return 0;
}