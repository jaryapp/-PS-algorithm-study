#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE	100

int N, M;
char map[MAX_SIZE+1][MAX_SIZE+1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

class Case {
public:
	int y;
	int x;
	int destory = 0;
};

void push(queue<Case>& Q,int y, int x, int destory) {
	if (y < 0 || x < 0 || y >= N || x >= M) return;
	if (map[y][x] == '1') {
		destory++;
	}

	if (dp[y][x] != -1 && dp[y][x] <= destory) return;

	dp[y][x] = destory;
	Q.push({ y,x,destory });

}


void bfs() {

	queue<Case> Q;

	Q.push({ 0, 0, 0 });




	while (!Q.empty())
	{
		Case c = Q.front();
		Q.pop();

		push(Q, c.y + 1, c.x, c.destory);
		push(Q, c.y - 1, c.x, c.destory);
		push(Q, c.y, c.x+1, c.destory);
		push(Q, c.y, c.x-1, c.destory);


	}
}


int main(void) {

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			dp[i][j] = -1;
		}
	}

	dp[0][0] = 0;
	bfs();

	cout << dp[N - 1][M - 1];
	

	return 0;
}