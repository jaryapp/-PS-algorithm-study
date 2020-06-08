#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Country {
public:
	int win = 0;
	int draw = 0;
	int lose = 0;
};

Country country[6];


map<string, bool> visited;

string str[4];
bool pos[4] = { false, };

string s = "000000000000000000";
void dfs(int i, int j) {

	if (j >= 6) {
		i++;
		j = i + 1;
	}

	if (i >= 5) {
		//s.reserve(20);
		for (int k = 0; k < 6; k++) {
			s[k * 3] = country[k].win + '0';
			s[k * 3 + 1] = country[k].draw + '0';
			s[k * 3 + 2] = country[k].lose + '0';
		}
		for (int a = 0; a < 4; a++) {
			if (pos[a]) continue;
			if (str[a] == s) {
				pos[a] = true;
			}
		}
		return;
	}

	country[i].win++;
	country[j].lose++;
	dfs(i, j + 1);
	country[i].win--;
	country[j].lose--;

	country[j].win++;
	country[i].lose++;
	dfs(i, j + 1);
	country[j].win--;
	country[i].lose--;

	country[i].draw++;
	country[j].draw++;
	dfs(i, j + 1);
	country[i].draw--;
	country[j].draw--;


}

int main(void) {

	for (int i = 0; i < 4; i++) {
		str[i] = "000000000000000000";
		for (int k = 0; k < 18; k++) {
			int num;
			scanf("%d", &num);
			str[i][k] = num + '0';
		}

	}


	dfs(0, 1);

	for (int i = 0; i < 4; i++) {
		printf("%d ", pos[i] ? 1 : 0);
	}

	return 0;
}