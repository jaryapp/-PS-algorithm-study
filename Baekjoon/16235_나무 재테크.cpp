#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int A[15][15];
int map[15][15];
int N, M, K;

class Tree {
public:
	int y;
	int x;
	int age;
	bool live = true;
};

//vector<Tree> tree[2];

Tree tree[2][1000000];

queue<Tree> stree[2];

queue<Tree> die;
queue<Tree> live;


int ctree[2] = { 0, };




bool spring();
void summer();
void fall();
void winter();

int year = 0;
int flag;
int next_flag;

// 오름차순 정렬
struct cmp {
	bool operator()(Tree t1, Tree t2) {
		return t1.age < t2.age;
	}
};


bool compare(Tree t1, Tree t2) {
	return t1.age < t2.age;
}

priority_queue< Tree, vector<Tree>, cmp > pq;


bool spring() {
	year++;
	flag = year % 2;
	next_flag = (year + 1) % 2;
	//tree[next_flag].clear();
	if (year == K + 1) return true;
	ctree[next_flag] = 0;
	ctree[flag] = 0;

	//sort(tree[flag], tree[flag] + ctree[flag], compare);


	while (!stree[flag].empty()) {

		Tree t = stree[flag].front();
		stree[flag].pop();
		if (map[t.y][t.x] >= t.age) {
			map[t.y][t.x] -= t.age;
			t.age++;
			live.push(t);
			//stree[next_flag].push(t);
		}
		else {
			t.live = false;
			die.push(t);
		}


	}

	return false;
}

void summer() {

	while (!die.empty()) {
		Tree t = die.front();
		die.pop();
		map[t.y][t.x] += t.age / 2;
	}

}

void bunsick(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > N) return;
	Tree t = { y,x,1 };
	stree[next_flag].push(t);
	/*pq.push(t);
	tree[next_flag][ctree[next_flag]] = t;
	ctree[next_flag]++;*/
}

void fall() {

	while (!live.empty()) {
		Tree t = live.front();
		live.pop();
		die.push(t);
		//stree[next_flag].push(t);
		if (t.age % 5 == 0) {
			bunsick(t.y - 1, t.x - 1);
			bunsick(t.y - 1, t.x);
			bunsick(t.y - 1, t.x + 1);
			bunsick(t.y, t.x - 1);
			bunsick(t.y, t.x + 1);
			bunsick(t.y + 1, t.x - 1);
			bunsick(t.y + 1, t.x);
			bunsick(t.y + 1, t.x + 1);
		}
	}

	while (!die.empty()) {
		Tree t = die.front();
		die.pop();
		stree[next_flag].push(t);
	}

}

void winter() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += A[i][j];
		}
	}
}



int main(void) {

	scanf("%d %d %d", &N, &M, &K);


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}
	}

	for (int k = 0; k < M; k++) {
		int y, x, age;
		scanf("%d %d %d", &y, &x, &age);
		Tree t = { y,x,age };
		//tree[1][ctree[1]] = t;
		//ctree[1]++;

		stree[1].push(t);
		//pq.push(t);
	}

	while (true) {


		if (spring()) break;
		summer();
		fall();
		winter();
	}

	printf("%d", stree[flag].size());
}