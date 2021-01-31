#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>


using namespace std;

#define MAX_SIZE	200
#define MAX_K		30


class Monkey {
public:
	int y;
	int x;
	int move = 0;
	int k = 0;
};

int K, W, H;
queue<Monkey> Q;
int map[MAX_SIZE + 1][MAX_SIZE + 1];
int visited[MAX_SIZE + 1][MAX_SIZE + 1][MAX_K+1] = { 0, };

void move(Monkey m) {
	if (m.y < 0 || m.x < 0 || m.y >= H || m.x >= W) return;
	if (map[m.y][m.x] == 1) return;
	if (visited[m.y][m.x][m.k] != 0 && visited[m.y][m.x][m.k] <= m.move) return;
	visited[m.y][m.x][m.k] = m.move;
	Q.push(m);
}

void bfs() {
	while (!Q.empty()) {
		Monkey cur = Q.front();
		Q.pop();
		if (cur.k < K) {
			move({ cur.y - 1,cur.x - 2,cur.move + 1,cur.k + 1 });
			move({ cur.y - 2,cur.x - 1,cur.move + 1,cur.k + 1 });
			move({ cur.y - 2,cur.x + 1,cur.move + 1,cur.k + 1 });
			move({ cur.y - 1,cur.x + 2,cur.move + 1,cur.k + 1 });
			move({ cur.y + 1,cur.x + 2,cur.move + 1,cur.k + 1 });
			move({ cur.y + 2,cur.x + 1,cur.move + 1,cur.k + 1 });
			move({ cur.y + 2,cur.x - 1,cur.move + 1,cur.k + 1 });
			move({ cur.y + 1,cur.x - 2,cur.move + 1,cur.k + 1 });
		}

		move({ cur.y + 1,cur.x,cur.move + 1,cur.k });
		move({ cur.y - 1,cur.x,cur.move + 1,cur.k });
		move({ cur.y,cur.x + 1,cur.move + 1,cur.k });
		move({ cur.y,cur.x - 1,cur.move + 1,cur.k });

	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;
	cin >> W >> H;

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> map[h][w];
		}
	}

	move({ 0,0,0,0 });


	bfs();

	int mn = INT_MAX;

	for (int i = 0; i <= K; i++) {
		int move = visited[H - 1][W - 1][i];
		if (move != 0) {
			mn = min(mn, move);
		}
	}

	if (W == 1 && H == 1) mn = 0;
	else if (mn == INT_MAX) mn = -1;

	cout << mn;


	


	return 0;
}