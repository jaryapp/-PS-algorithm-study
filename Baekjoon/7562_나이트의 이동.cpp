#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

class Pos {
public:
	int y;
	int x;
	int cnt = 0;
};

queue<Pos> Q;

int dy[] = { -1,-2,-2,-1, 1, 2,  2,  1 };
int dx[] = { -2,-1, 1, 2, 2, 1, -1, -2 };

int I;

bool visited[310][310];

void push(int y, int x,int cnt) {
	if (x < 0 || y < 0 || x >= I || y >= I) return;
	Q.push({ y,x,cnt});
}


int bfs(int y, int x,int ty,int tx) {

	Q.push({ y,x,0 });

	while (!Q.empty()) {

		Pos p = Q.front();
		Q.pop();

		if (p.x == tx && p.y == ty) return p.cnt;
		if (visited[p.y][p.x]) continue;
		visited[p.y][p.x] = true;

		for (int i = 0; i < 8; i++) {
			push(p.y + dy[i], p.x + dx[i],p.cnt+1);
		}

	}


}



int main(void) {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));

		while (!Q.empty())
		{
			Q.pop();
		}

		scanf("%d", &I);

		int x, y, tx, ty;

		scanf("%d %d", &x, &y);
		scanf("%d %d", &tx, &ty);

		int cnt = bfs(y, x, ty, tx);

		printf("%d\n", cnt);

	}

	return 0;
}