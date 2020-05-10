#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool visited[102];

int number[102];

bool dfs(int start, int cur) {

	if (cur == start) return true;
	else if (visited[cur]) return false;
	else {
		visited[cur] = true;
		return dfs(start, number[cur]);
	}

}

int main(void) {
	
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &number[i]);
	}


	vector<int> v;
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i, number[i])) {
			v.push_back(i);
		}
	}

	printf("%d\n", v.size());

	for (auto n : v) {
		printf("%d\n", n);
	}


}