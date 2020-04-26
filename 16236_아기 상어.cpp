#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;


#define IMPOSSIBLE 10000

class Pos {
public:
	int y;
	int x;
	int size;
	bool die = false;
	int check = 0;
};

int map[25][25];
vector<Pos> fish;
vector<Pos*> eat_possible;
Pos shark;
int N;
int time = 0;

bool visited[25][25] = { false, };

bool compare(Pos* A, Pos *B) {
	if (A->y == B->y) {
		return A->x < B->x;
	}
	else return A->y < B->y;

}

int dist(Pos d1, Pos d2) {

	queue<Pos> Q;

	Q.push(d1);

	while (!Q.empty()) {
		Pos n = Q.front();
		Q.pop();
		if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N) continue;
		if (visited[n.y][n.x]) continue;
		if (shark.size < map[n.y][n.x]) continue;

		visited[n.y][n.x] = true;


		if (n.x == d2.x && n.y == d2.y) {
			return n.check;
		}

		Q.push({ n.y+1,n.x,n.size,n.die,n.check + 1 });
		Q.push({ n.y-1,n.x,n.size,n.die,n.check + 1 });
		Q.push({ n.y,n.x+1,n.size,n.die,n.check + 1 });
		Q.push({ n.y,n.x-1,n.size,n.die,n.check + 1 });

	
	}

	return IMPOSSIBLE;



}

int find() {

	int fs = fish.size();

	int mn = INT_MAX;

	eat_possible.clear();
	for (int i = 0; i < fs; i++) {
		if (fish[i].die) continue;
		if (shark.size <= fish[i].size) continue;

		memset(visited, 0, sizeof(visited));
		int d = dist(shark, fish[i]);
		if (d >= IMPOSSIBLE) continue;
		if (d < mn) {
			mn = d;
			eat_possible.clear();
			eat_possible.push_back(&fish[i]);
		}
		else if(d==mn) {
			eat_possible.push_back(&fish[i]);
		}
	}

	sort(eat_possible.begin(), eat_possible.end(), compare);

	if (eat_possible.empty()) return 0;
	else return mn;
}

void eat() {

	int eat_cnt = 0;

	while (true) {
		int d = find();
		if (d == 0) return;
		Pos* target_fish = eat_possible[0];
		target_fish->die = true;
		time += d;
		eat_cnt++;
		shark.x = target_fish->x;
		shark.y = target_fish->y;
		//printf("y : %d x : %d %d %d\n", target_fish->y, target_fish->x,d,time);
		if (shark.size == eat_cnt) {
			shark.size++;
			eat_cnt = 0;
		}

	}
}

int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			scanf("%d", &num);
			map[i][j] = num;
			if (num == 9) {
				shark.y = i;
				shark.x = j;
				shark.size = 2;
				map[i][j] = 0;
			}
			else if (num >= 1 && num <= 6) {
				fish.push_back({ i,j,num });
			}
		}
	}

	eat();

	printf("%d", time);

	return 0;
}
