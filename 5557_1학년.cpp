#include <iostream>

using namespace std;

long long dp[102][21];
int arr[102];
int N;


long long calc(int idx, int sum) {

	if (idx == N - 1) {
		if (sum == arr[idx]) return 1;
		else return 0;
	}
	if (sum < 0 || sum > 20) return 0;

	if (dp[idx][sum] != -1) return dp[idx][sum];
	dp[idx][sum] = 0;
	dp[idx][sum] += calc(idx + 1, sum + arr[idx]);
	dp[idx][sum] += calc(idx + 1, sum - arr[idx]);

	return dp[idx][sum];
}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);


	for (int i = 0; i < 102; i++) {
		fill_n(dp[i], 21, -1);
	}


	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	calc(1, arr[0]);

	cout << dp[1][arr[0]];




	return 0;
}