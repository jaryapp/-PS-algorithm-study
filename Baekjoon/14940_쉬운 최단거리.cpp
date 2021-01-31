#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;


class Pos {
public:
	int y;
	int x;
	int dist = 0;
};

int map[1002][1002];
bool visited[1002][1002];

int N, M;

Pos target;

void printMap() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visited[i][j]) map[i][j] = -1;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}


void dist(Pos start) {

	queue<Pos> Q;

	Q.push(start);

	while (!Q.empty()) {
		Pos n = Q.front();
		Q.pop();
		if (n.x < 0 || n.y < 0 || n.x >= M || n.y >= N) continue;
		if (map[n.y][n.x] == 0) continue;
		if (visited[n.y][n.x]) continue;

		visited[n.y][n.x] = true;

		map[n.y][n.x] = n.dist;


		Q.push({ n.y + 1,n.x,n.dist + 1 });
		Q.push({ n.y - 1,n.x,n.dist + 1 });
		Q.push({ n.y,n.x + 1,n.dist + 1 });
		Q.push({ n.y,n.x - 1,n.dist + 1 });


	}


}


int main(void) {

	scanf("%d %d", &N,&M);

	Pos target;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			scanf("%d", &num);
			map[i][j] = num;
			if (num == 2) {
				target.y = i;
				target.x = j;
				target.dist = 0;
			}

		}
	}

	dist(target);

	printMap();



	return 0;
}
