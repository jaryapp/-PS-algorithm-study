#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class pos {
public:
	int x;
	int y;
};

vector<pos> v;
int N, M;

int map[302][302] = { 0, };

void check1(int k[][302], int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return;
	if (k[y][x]) return;
	if (map[y][x]) {
		k[y][x] = 1;
		check1(k, y, x + 1);
		check1(k, y, x - 1);
		check1(k, y + 1, x);
		check1(k, y - 1, x);
	}
}

void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool isSea(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return false;
	if (map[y][x] == 0) return true;
	else return false;
}


int main() {


	scanf("%d %d", &N, &M);


	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			map[i][j] = num;
			if (num) {
				pos p;
				p.y = i;
				p.x = j;
				v.push_back(p);
			}
		}
	}

	int year = 0;
	bool suc = false;

	while (true) {
		year++;
		int bing = 0;
		int size = v.size();
		int dec[302][302] = { 0, };
		for (int i = 0; i < size; i++) {
			pos p = v[i];
			if (map[p.y][p.x]) {
				int cntSea = 0;
				if (isSea(p.y, p.x + 1)) cntSea++;
				if (isSea(p.y, p.x - 1)) cntSea++;
				if (isSea(p.y+1, p.x)) cntSea++;
				if (isSea(p.y-1, p.x )) cntSea++;
				dec[p.y][p.x] = cntSea;
				bing++;
			}
		}

		for (int i = 0; i < size; i++) {
			pos p = v[i];
			if (map[p.y][p.x]) {
				map[p.y][p.x] -= dec[p.y][p.x];
				if (map[p.y][p.x] < 0) map[p.y][p.x] = 0;
			}
		}


		int cnt = 0;
		int k[302][302] = { 0, };

		for (int i = 0; i < size; i++) {
			pos p = v[i];
			if (map[p.y][p.x] && k[p.y][p.x] == 0) {
				cnt++;
				check1(k, p.y, p.x);
			}
		}

		//printMap();

		if (cnt >= 2) {
			suc = true;
			break;
		}
		if (bing == 0) break;

	}

	if (suc) printf("%d", year);
	else printf("0");

	return 0;
}