#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M;

char map[12][12];

bool visited[12][12][12][12] = { false, };

class Ball {
public:
	int y;
	int x;
	bool same(Ball b1) {
		if (y == b1.y && x == b1.x) return true;
		else return false;
	}
};

class Item {
public:
	Ball R;
	Ball B;
	int cnt = 0;
};

void show(Ball R, Ball B) {
	map[R.y][R.x] = 'R';
	map[B.y][B.x] = 'B';

	for (int i = 0; i < N; i++) {
		printf("%s\n", map[i]);
	}

	map[R.y][R.x] = '.';
	map[B.y][B.x] = '.';

	printf("\n");


}

queue<Item> Q;
int moveDown(Ball R, Ball B, int cnt) {

	int holeR = 0;
	int holeB = 0;

	if (R.y > B.y) {
		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.y--;
				break;
			}
			R.y++;
		}

		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.y--;
				break;
			}
			B.y++;
		}

	}
	else {
		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.y--;
				break;
			}
			B.y++;
		}

		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.y--;
				break;
			}
			R.y++;
		}

	}

	//show(R, B);

	if (holeR == 1 && holeB == 0) {
		return 1;
	}

	if (holeR == 0 && holeB == 0) {
		Q.push({ R,B,cnt });
	}

	return 0;


}

int moveUp(Ball R, Ball B, int cnt) {

	int holeR = 0;
	int holeB = 0;

	if (R.y < B.y) {
		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.y++;
				break;
			}
			R.y--;
		}

		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.y++;
				break;
			}
			B.y--;
		}

	}
	else {
		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.y++;
				break;
			}
			B.y--;
		}

		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.y++;
				break;
			}
			R.y--;
		}

	}

	//show(R,B);

	if (holeR == 1 && holeB == 0) {
		return 1;
	}

	if (holeR == 0 && holeB == 0) {
		Q.push({ R,B,cnt });
	}

	return 0;


}


int moveRight(Ball R, Ball B, int cnt) {

	int holeR = 0;
	int holeB = 0;

	if (R.x > B.x) {
		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.x--;
				break;
			}
			R.x++;
		}

		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.x--;
				break;
			}
			B.x++;
		}

	}
	else {
		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.x--;
				break;
			}
			B.x++;
		}

		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.x--;
				break;
			}
			R.x++;
		}

	}

	//show(R,B);

	if (holeR == 1 && holeB == 0) {
		return 1;
	}

	if (holeR == 0 && holeB == 0) {
		Q.push({ R,B,cnt });
	}

	return 0;


}

int moveLeft(Ball R, Ball B, int cnt) {

	int holeR = 0;
	int holeB = 0;

	if (R.x < B.x) {
		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.x++;
				break;
			}
			R.x--;
		}

		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.x++;
				break;
			}
			B.x--;
		}

	}
	else {
		while (true) {
			if (map[B.y][B.x] == 'O') {
				holeB = 1;
			}
			if (map[B.y][B.x] == '#' || B.same(R)) {
				B.x++;
				break;
			}
			B.x--;
		}

		while (true) {
			if (map[R.y][R.x] == 'O') {
				holeR = 1;
			}
			if (map[R.y][R.x] == '#' || B.same(R)) {
				R.x++;
				break;
			}
			R.x--;
		}

	}

	//show(R,B);

	if (holeR == 1 && holeB == 0) {
		return 1;
	}

	if (holeR == 0 && holeB == 0) {
		Q.push({ R,B,cnt });
	}

	return 0;


}




int bfs(Ball sR, Ball sB) {
	Q.push({ sR, sB, 0 });
	while (!Q.empty()) {
		Item it = Q.front();
		Q.pop();
		Ball R = it.R;
		Ball B = it.B;
		if (visited[R.y][R.x][B.y][B.x]) continue;
		visited[R.y][R.x][B.y][B.x] = true;

		if (it.cnt >= 10) return -1;
		
		if (moveUp(R, B, it.cnt + 1)) {
			return it.cnt + 1;
		}
		if (moveLeft(R, B, it.cnt + 1)) {
			return it.cnt + 1;
		}
		if (moveRight(R, B, it.cnt + 1)) {
			return it.cnt + 1;
		}
		if (moveDown(R, B, it.cnt + 1)) {
			return it.cnt + 1;
		}
	}

	return -1;
}

Ball hole;

int main(void) {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}

	Ball R;
	Ball B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				R.y = i;
				R.x = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				B.y = i;
				B.x = j;
				map[i][j] = '.';
			}
		}
	}

	printf("%d", bfs(R, B));

	return 0;
}