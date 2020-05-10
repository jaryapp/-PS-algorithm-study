#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;
bool visited[502];
bool graph[502][502];

class Item {
public:
	int num;
	int depth = 0;
};

int bfs() {
	queue<Item> Q;
	Q.push({ 1, 0});
	int cnt = 0;

	while (!Q.empty()) {
		Item item = Q.front();
		Q.pop();
		if (visited[item.num]) continue;
		visited[item.num] = true;
		cnt++;
		if (item.depth == 2) continue;
		for (int i = 1; i <= n; i++) {
			if (graph[item.num][i] && !visited[i]) {
				Q.push({i,item.depth+1});
			}
		}
	}

	return cnt - 1;

}

int main(void) {

	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	printf("%d", bfs());

	return 0;
}