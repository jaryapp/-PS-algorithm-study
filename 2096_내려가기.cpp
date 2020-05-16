#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int getMax(int a, int b, int c) {
	int m = max(a, b);
	return max(m, c);
}

int getMin(int a, int b, int c) {
	int m = min(a, b);
	return min(m, c);
}


int main(void) {

	int N;

	int dp[2][5];
	int dpx[2][5];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int cur = i % 2;
		int bfr = (i + 1) % 2;
		for (int j = 1; j < 4; j++) {
			scanf("%d", &dp[cur][j]);
		}


		dpx[cur][0] = 0;
		dpx[cur][4] = 0;

		if (i > 0) {
			for (int j = 1; j < 4; j++) {
				dpx[cur][j] = dp[cur][j] + getMax(dpx[bfr][j - 1], dpx[bfr][j], dpx[bfr][j + 1]);
			}
		}
		else {
			dpx[i][1] = dp[i][1];
			dpx[i][2] = dp[i][2];
			dpx[i][3] = dp[i][3];
		}

		dp[cur][0] = INT_MAX;
		dp[cur][4] = INT_MAX;

		if (i > 0) {
			for (int j = 1; j < 4; j++) {
				dp[cur][j] = dp[cur][j] + getMin(dp[bfr][j - 1], dp[bfr][j], dp[bfr][j + 1]);
			}
		}
		else {
			dp[i][1] = dp[i][1];
			dp[i][2] = dp[i][2];
			dp[i][3] = dp[i][3];
		}
	}

	int cur = (N-1) % 2;

	printf("%d", getMax(dpx[cur][1], dpx[cur][2], dpx[cur][3]));

	printf(" %d", getMin(dp[cur][1], dp[cur][2], dp[cur][3]));

	return 0;
}