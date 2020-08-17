#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_D 10000
#define INIT_NUM 99999999

class Shrotcut {
public:
	int st;
	int en;
	int dist;
};

int N, D;

vector<Shrotcut> shortcut[MAX_D+2];

bool compare(Shrotcut a, Shrotcut b) {
	if (a.en < b.en) return true;
	else if (a.en == b.en) {
		if (a.dist < b.dist) return true;
		else return false;
	}
	else return false;
}

int main() {

	freopen("data.txt", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> D;

	int st, en, dist;

	for (int i = 0; i < N; i++) {
		cin >> st >> en >> dist;
		shortcut[en].push_back({ st,en,dist });
	}


	int dp[MAX_D + 2];
	

	fill_n(dp, MAX_D + 2, INIT_NUM);
	dp[0] = 0;

	for (int i = 0; i <= D; i++) {
		for (auto s : shortcut[i]) {
			if (dp[s.en] > dp[s.st] + s.dist) {
				dp[s.en] = dp[s.st] + s.dist;
			}
		}
		if (i!= 0 && dp[i] > dp[i - 1] + 1) {
			dp[i] = dp[i - 1] + 1;
		}
	}


	cout << dp[D];



	return 0;
}