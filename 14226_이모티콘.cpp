#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX_S 1000 + 5

bool visited[MAX_S][MAX_S] = { 0, };


class Case {
public:
	int cnt = 0;
	int clipboard = 0;
	int second = 0;
};

int S;

int bfs() {

	queue<Case> Q;
	Q.push({ 1,0,0 });

	while (!Q.empty())
	{
		Case c = Q.front();
		Q.pop();


		if (c.cnt == S) return c.second;

		if (c.cnt >= MAX_S) continue;
		if (visited[c.cnt][c.clipboard]) continue;
		visited[c.cnt][c.clipboard] = true;

		// 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
		Q.push({ c.cnt,c.cnt,c.second + 1 });

		// 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		if(c.clipboard) Q.push({ c.cnt + c.clipboard,c.clipboard,c.second + 1 });

		// 화면에 있는 이모티콘 중 하나를 삭제한다
		if (c.cnt) Q.push({ c.cnt-1,c.clipboard,c.second + 1 });
	}

}

int main(void) {

	scanf("%d", &S);

	printf("%d", bfs());

	return 0;
}