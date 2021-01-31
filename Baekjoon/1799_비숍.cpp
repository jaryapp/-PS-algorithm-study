#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 11
int N;
int case_cnt = 0;

bool map[MAX_N + 1][MAX_N + 1] = { 0, };
int dir[4][2] = { { 1,1 },{ 1,-1 },{ -1,1 },{ -1,-1 } };

int max_cnt = 0;


void showMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}


void set(int y, int x) {
	map[y][x] = false;

	for (int i = 0; i < 4; i++) {
		int c_x = x;
		int c_y = y;
		while (true) {
			y += dir[i][0];
			x += dir[i][1];
			if (y >= N || x >= N || x < 0 || y < 0)break;
			map[y][x] = false;
		}
		x = c_x;
		y = c_y;
	}

	//showMap();
	//printf("\n");


}

void bishop(int y, int x, int cnt, int k) {


	bool cpy_map[MAX_N + 1][MAX_N + 1] = { 0, };

	memcpy(cpy_map, map, sizeof(map));

	if (y >= 0 && x >= 0 &&map[y][x]) {
		set(y, x);
		cnt += 1;
		max_cnt = cnt > max_cnt ? cnt : max_cnt;
	}

	int tx, ty;

	if (k < N) {
		tx = k;
		ty = 0;
	}
	else if (k <= 2 * (N-1)) {
		tx = N - 1;
		ty = k - N + 1;

	}
	else return;

	//printf("%d - y %d x:%d\n", k, ty, tx);

	bool go = false;


	while (true) {
		//printf("%d - y %d x:%d\n", k, ty, tx);
		if (map[ty][tx]) {
			go = true;
			bishop(ty, tx, cnt, k + 1);
		}
		tx--;
		ty++;
		if (tx < 0 || ty < 0 || tx >= N || ty >= N) break;
	}

	if(!go)bishop(ty, tx, cnt, k + 1);


	memcpy(map, cpy_map, sizeof(map));
}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			scanf("%d", &n);
			if (n) map[i][j] = true;
			else map[i][j] = false;
			//scanf("%d", map[i][j]);
		}
	}

	bishop(-1, -1, 0,0);


	printf("%d", max_cnt);


	return 0;
}