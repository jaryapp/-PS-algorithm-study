#include <stdio.h>
#include <iostream>

using namespace std;

char board[22][22];
bool visited[200] = { false, };
int R, C;
int answer = 0;

void dfs(int y, int x, int depth) {
	if (y < 0 || x < 0 || y >= R || x >= C) return;
	if (visited[board[y][x]]) return;
	visited[board[y][x]] = true;
	answer = depth > answer ? depth : answer;
	dfs(y + 1, x, depth + 1);
	dfs(y - 1, x, depth + 1);
	dfs(y, x-1, depth + 1);
	dfs(y, x + 1, depth + 1);
	visited[board[y][x]] = false;

}

int main(void) {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		scanf("%s", board[i]);
	}
	dfs(0, 0, 1);
	printf("%d", answer);
	return 0;
}