#include <stdio.h>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int map[25][25];
int answer = INT_MIN;

vector<char> turn;

void show() {
	for (char t : turn) {
		printf("%c ",t);
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

}

void moveUp() {
	bool visited[25][25] = { false, };
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (map[y][x]) {
				int v = map[y][x];
				map[y][x] = 0;
				int ty = y - 1;
				while (map[ty][x] == 0 && ty >= 0) ty--;
				if (ty < 0) ty = 0;
				if ( map[ty][x]) {
					if (!visited[ty][x] && map[ty][x] == v) {
						visited[ty][x] = true;
						map[ty][x] += v;
					}
					else {
						map[ty + 1][x] = v;
					}
				}
				else map[ty][x] = v;
			}
		}
	}

}

void moveDown() {
	bool visited[25][25] = { false, };
	for (int x = 0; x < N; x++) {
		for (int y = N - 1; y >= 0; y--) {
			if (map[y][x]) {
				int v = map[y][x];
				map[y][x] = 0;
				int ty = y+1;
				while (map[ty][x] == 0 && ty < N) ty++;
				if (ty >= N) ty = N - 1;
				if ( map[ty][x]) {
					if (!visited[ty][x] && map[ty][x] == v) {
						visited[ty][x] = true;
						map[ty][x] += v;
					}
					else {
						map[ty-1][x] = v;
					}
				}
				else map[ty][x] = v;
			}
		}
	}

}

void moveRight() {
	bool visited[25][25] = { false, };
	for (int y = 0; y < N; y++) {
		for (int x = N - 1; x >= 0; x--) {
			if (map[y][x]) {
				int v = map[y][x];
				map[y][x] = 0;
				int tx = x + 1;
				while (map[y][tx] == 0 && tx < N) tx++;
				if (tx >= N) tx = N - 1;
				if ( map[y][tx]) {
					if (!visited[y][tx] && map[y][tx] == v) {
						visited[y][tx] = true;
						map[y][tx] += v;
					}
					else {
						map[y][tx-1] = v;
					}
				}
				else map[y][tx] = v;
			}
		}
	}

}

void moveLeft() {

	bool visited[25][25] = { false, };

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x]) {
				int v = map[y][x];
				map[y][x] = 0;
				int tx = x - 1;
				while (map[y][tx] == 0 && tx >= 0) tx--;
				if (tx < 0) tx = 0;
				if (map[y][tx]) {
					if (!visited[y][tx] && map[y][tx] == v) {
						visited[y][tx] = true;
						map[y][tx] += v;
					}
					else {
						map[y][tx + 1] = v;
					}
				}
				else map[y][tx] = v;
			}
		}
	}

}

void check() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer = max(answer, map[i][j]);
		}
	}

}

void dfs(int depth) {
	//show();

	if (depth > 5) {
		check();
		return;
	}

	int cpy_map[25][25];
	memcpy(cpy_map, map, sizeof(map));

	moveUp();
	turn.push_back('U');
	dfs(depth + 1);
	turn.pop_back();

	memcpy(map, cpy_map, sizeof(map));
	moveDown();
	turn.push_back('D');
	dfs(depth + 1);
	turn.pop_back();

	memcpy(map, cpy_map, sizeof(map));
	moveLeft();
	turn.push_back('L');
	dfs(depth + 1);
	turn.pop_back();

	memcpy(map, cpy_map, sizeof(map));
	moveRight();
	turn.push_back('R');
	dfs(depth + 1);
	turn.pop_back();


}


int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(1);

	/*while (true) {
		char ch = getchar();
		if (ch == '4') {
			moveLeft();
		}
		if (ch == '8') {
			moveUp();
		}
		if (ch == '6') {
			moveRight();
		}
		if (ch == '5') {
			moveDown();
		}
		show();
	}*/

	printf("%d", answer);

 	return 0;

}