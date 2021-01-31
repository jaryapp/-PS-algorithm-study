#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;


int A[60][60];
bool visited[60][60] = { false, };

int N, L, R;

class Pos {
public:
	int y;
	int x;
	int bfr_num;
};

vector<Pos> yunhap;
queue<Pos> Q;

int move_count = 0;

void show() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}


void move(int sum) {
	int sz = yunhap.size();
	for (auto v : yunhap) {
		A[v.y][v.x] = sum / sz;
	}
	//move_count++;
	//show();
}

bool bfs(int y, int x) {

	int sum = 0;
	Q.push({ y,x,-1 });
	while (!Q.empty()) {
		Pos p = Q.front();
		Q.pop();
		if (p.y < 0 || p.x < 0 || p.y >= N || p.x >= N) continue;
		// 처음
		if (p.bfr_num != -1) {
			int dist = abs(A[p.y][p.x] - p.bfr_num);
			if (!(L <= dist && dist <= R)) continue;
		}
		if (visited[p.y][p.x]) continue;
		visited[p.y][p.x] = true;
		sum += A[p.y][p.x];
		yunhap.push_back(p);
		Q.push({ p.y + 1,p.x,A[p.y][p.x] });
		Q.push({ p.y - 1,p.x,A[p.y][p.x] });
		Q.push({ p.y,p.x + 1,A[p.y][p.x] });
		Q.push({ p.y,p.x - 1,A[p.y][p.x] });
	}

	if (yunhap.size() > 1) {
		move(sum);
		return true;
	}
	else return false;

}

bool day() {

	memset(visited, false, sizeof(visited));
	bool chk = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			yunhap.clear();
			chk = chk + bfs(i, j);
		}
	}
	return chk;
}


int main(void) {

	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}


	//show();

	//bfs(0,0);

	 //for (int i = 0; i < N; i++) {
	 //	for (int j = 0; j < N; j++) {
	 //		 while (true) {
	 //		 	memset(visited, false, sizeof(visited));
		//		yunhap.clear();
	 //		 	if(!bfs(i, j)) break;
	 //		 	//bfs(i, j);
	 //		 }
	 //		//bfs(i, j);
	 //	}
	 //}

	 while (true) {
		 if (day()) {
			 move_count++;
		 }
		 else break;
	 }

	printf("%d", move_count);




	return 0;
}