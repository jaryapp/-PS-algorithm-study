#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_SIZE 12

char map[15][7];

bool visited[15][7] = { false, };


void showMap() {
	for (int i = 0; i < 12; i++) {
		printf("%s\n", map[i]);
	}
	printf("\n\n");

}

void gravity() {

	for (int i = MAX_SIZE - 1; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != '.') {
				int k = i + 1;

				while (map[k][j] == '.') {
					map[k][j] = map[k - 1][j];
					map[k - 1][j] = '.';
					k++;
					if (k >= 12) break;
				}

			}
		}
	}

}

int cntPyPy(int y, int x, char color) {
	if (y < 0 || x < 0 || y >= 12 || x >= 12) return 0;
	if (visited[y][x]) return 0;
	if (color != map[y][x]) return 0;

	visited[y][x] = true;

	return 1 + cntPyPy(y + 1, x, color) + cntPyPy(y - 1, x, color) + cntPyPy(y, x + 1, color) + cntPyPy(y, x - 1, color);
}

bool isBoom(int y, int x) {
	if (visited[y][x]) return false;

	int cnt = 0;

	cnt += cntPyPy(y, x, map[y][x]);

	if (cnt >= 4) return true;
	else return false;

}

void boom(int y, int x, char color) {
	if (y < 0 || x < 0 || y >= 12 || x >= 12) return;
	if (map[y][x] != color) return;
	map[y][x] = '.';
	boom(y + 1, x, color);
	boom(y - 1, x, color);
	boom(y, x + 1, color);
	boom(y, x - 1, color);
}

int main(void) {
	for (int i = 0; i < 12; i++) {
		scanf("%s", map[i]);
	}


	int cnt = 0;
	int bfr = 0;
	int answer = 0;

	while (true) {

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					if (isBoom(i, j)) {
						boom(i, j, map[i][j]);
						cnt++;
					}
				}
			}
		}

		if (bfr == cnt) break;
		bfr = cnt;
		answer++;

		gravity();
		for (int i = 0; i < 12; i++) {
			fill_n(visited[i], 6, 0);
		}

	}


	printf("%d", answer);

}