#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

class Pos {
public:
	int y;
	int x;
	int time = 0;
};

vector<Pos> virus;
vector<Pos> space;
queue<Pos> Q;
vector<Pos> vv;
int map[60][60];
bool visited[60][60] = { false, };
int N, M;
int mx = 0;

//void getShowVirusMap() {
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			printf("%d ", virus_map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//
//}

bool isPossible() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) return false;
		}
	}

	return true;
}

int bfs() {

	int time = 0;

	for (auto it = vv.begin(); it != vv.end(); it++) {
		Q.push(*it);
	}

	while (!Q.empty()) {
		Pos p = Q.front();
		Q.pop();

		if (p.x < 0 || p.y < 0 || p.x >= N || p.y >= N) continue;
		if (map[p.y][p.x] == 1) continue;
		if (visited[p.y][p.x]) continue;
		visited[p.y][p.x] = true;

		time = p.time;

		Q.push({ p.y + 1,p.x,p.time + 1 });
		Q.push({ p.y - 1,p.x,p.time + 1 });
		Q.push({ p.y,p.x + 1,p.time + 1 });
		Q.push({ p.y,p.x - 1,p.time + 1 });
	}

	return isPossible() ? time : INT_MAX;
}


int mn = INT_MAX;
void dfs(int start, int depth) {
	if (depth == M) {
		int time = bfs();
		memset(visited, 0, sizeof(visited));
		mn = mn > time ? time :mn;
		return;
	}

	int vs = virus.size();

	for (int i = start; i < vs; i++) {
		vv.push_back({ virus[i].y,virus[i].x });
		dfs(i + 1, depth + 1);
		vv.pop_back();
	}
}


int main(void) {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back({ i, j });
				map[i][j] = 0;
			}
		}
	}

	dfs(0, 0);


	printf("%d", mn == INT_MAX ? -1:mn);


	return 0;
}