#include <iostream>
#include <limits.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<int> cnt;

long long total = 0;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int n;
		map<string, int> m;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			cin >> str;
			if (!m[str]) m[str] = 1;
			else m[str]++;
		}
		cnt.clear();
		total = 1;
		for (auto a = m.begin(); a != m.end(); a++) {
			total *= ((*a).second+1);
		}
		cout << total - 1 << '\n';
	}

	return 0;
}