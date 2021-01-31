#include <iostream>
#include <string>

using namespace std;

bool isValidate(int i) {
	return 1 <= i && i <= 26;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long dp[5003] = { 1 };
	string crypto;
	cin >> crypto;

	int i = 1;
	int bfr = 0;
	for (char v : crypto) {
		int cur = v - '0';

		if (isValidate(cur)) {
			dp[i] += dp[i - 1];
			dp[i] %= 1000000;
		}
		if (bfr != 0 && isValidate(bfr * 10 + cur)) {
			dp[i] += dp[i - 2];
			dp[i] %= 1000000;
		}
		if (!isValidate(cur) && !isValidate(bfr * 10 + cur)) {
			dp[i-1] = 0;
			break;
		}
		

		bfr = cur;
		i++;
	}

	printf("%lld", dp[i - 1]);
}