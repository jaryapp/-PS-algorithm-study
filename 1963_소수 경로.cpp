#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool visited[10000];
bool isSosu[10000];
vector<int> sosu;


class Case {
public:
	int number[4];
	int cnt = 0;
	Case(int num) {
		int i = 3;
		while (num) {
			this->number[i] = num % 10;
			num /= 10;
			i--;
		}
	}
	Case(Case *c) {
		for (int i = 0; i < 4; i++) {
			this->number[i] = c->number[i];
		}
		this->cnt = c->cnt;
	}
	bool change(int index, int number) {
		if (this->number[index] == number) return false;
		this->number[index] = number;
		if (!this->isNumberSosu()) return false;
		this->cnt++;
		return true;
	}
	int getNum() {
		int *num = this->number;
		return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
	}
	bool isNumberSosu() {
		int num = this->getNum();
		return isSosu[num];
	}
};

int bfs(int start, int target) {
	queue<Case*> Q;
	Q.push(new Case(start));
	while (!Q.empty()){

		Case *c = Q.front();
		Q.pop();
		if (visited[c->getNum()]) continue;
		visited[c->getNum()] = true;
		if (c->getNum() == target) return c->cnt;
		for (int n = 0; n < 4; n++) {
			for (int i = 0; i < 10; i++) {
				if (n == 0 && i == 0) continue;
				Case* t = new Case(c);
				if (t->change(n, i)) {
					Q.push(t);
				}
				else {
					delete t;
				}
			}
		}

		delete c;

	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	fill_n(isSosu, 10000, true);


	isSosu[0] = false;
	isSosu[1] = false;

	for (int i = 2; i < 10000; i++) {
		if (isSosu[i] == false) continue;
		if (i >= 1000) sosu.push_back(i);
		for (int k = i+i; k < 10000; k+=i) {
			isSosu[k] = false;
		}
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		fill_n(visited, 10000, false);
		int start, target;
		cin >> start >> target;
		int cnt = bfs(start, target);
		if (cnt == -1) cout << "Impossible" << "\n";
		else cout << cnt << "\n";
	}

	return 0;
}