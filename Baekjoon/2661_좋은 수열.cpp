#include <iostream>
#include <string>

using namespace std;


int N;

// 가능한가?
bool validate(string str) {

	int section = 2;
	
	int len = str.length();
	while (true) {
		int leftIdx = len - section;
		if (leftIdx < 0) break;
		int rightIdx = len - 1;
		bool isSame = true;
		int cnt = 0;
		while (true) {
			if (str[leftIdx] != str[rightIdx]) {
				isSame = false;
				break;
			}
			leftIdx--;
			rightIdx--;
			cnt++;
			if (cnt == section - 1) break;
			if (leftIdx < 0) {
				isSame = false;
				break;
			}
		}
		if (isSame) return false;
		section++;
	}

	return true;
}

bool dfs(string s, int n) {

	if (n == N) {
		cout << s;
		return true;
	}

	for (int i = 1; i <= 3; i++) {
		string str = s + (char)(i + '0');
		if (validate(str)) {
			if(dfs(str, n + 1)) return true;
		}
	}

	return false;

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N;
	dfs("1", 1);




	return 0;
}