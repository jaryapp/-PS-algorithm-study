#include <iostream>
#include <algorithm>
using namespace std;


int graph[802][802] = { 0, };
int N, E;

int minDist(int* arr,bool* visited) {
	int d = 9999999;
	int idx = 9999999;
	for (int i = 1; i <= N; i++) {
		if(visited[i]) continue;
		if (arr[i] < d) {
			d = arr[i];
			idx = i;
		}
	}
	
	if(idx == 9999999) return -1;
	
	visited[idx] = true;
	return idx;
}

int Dijkstra(int start, int end) {
	int dj[1000];
	bool visited[1000] = { 0, };
	int cnt = 1;
	fill_n(dj, 1000, 9999999);
	dj[start] = 0;
	
	while(true){
		int mnIdx = minDist(dj,visited);
		if(mnIdx == -1) break;
		for (int i = 1; i <= N; i++) {
			if (graph[mnIdx][i]) {
				dj[i] = min(dj[i], graph[mnIdx][i] + dj[mnIdx]);
			}
		}
	}


	return dj[end];

}

int main() {

	scanf("%d %d", &N, &E);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	}

	int m1, m2;

	scanf("%d %d", &m1, &m2);

	int dist = min(Dijkstra(1, m1) + Dijkstra(m1, m2) + Dijkstra(m2, N),
	               Dijkstra(1, m2) + Dijkstra(m2, m1) + Dijkstra(m1, N));
   if(dist >= 9999999) printf("-1");
   else printf("%d",dist);
	
	return 0;
}