#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>


using namespace std;

int R, C, M;

class Shark {
public:
	int r;
	int c;
	int speed;
	//dir가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
	int dir;
	int size;
	bool live = true;
};

vector<Shark> shark;

int person_x;
int score = 0;

int board[110][110];

void fightShark() {

	int sz = shark.size();

	for (int i = 0; i < sz; i++) {
		Shark& cur = shark[i];

		if (cur.live == false) continue;

		// 이미 상어가 존재하다면 FIGHT!!
		if (board[cur.r][cur.c] >= 0) {
			Shark& bfr = shark[board[cur.r][cur.c]];
			if (cur.size > bfr.size) {
				// 기존 상어 패배
				bfr.live = false;
				board[cur.r][cur.c] = i;
			}
			// 새로운 상어 패배
			else cur.live = false;
		}
		else board[cur.r][cur.c] = i;
	}

}


void moveShark(Shark& s) {
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,1,-1 };

	//dir가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
	int d = s.dir - 1;
	//d가 0인 경우는 위, 1인 경우는 아래, 2인 경우는 오른쪽, 3인 경우는 왼쪽
	int speed = s.speed;

	if (d == 0 || d == 1) {
		speed %= R * 2 - 2;
	}
	else speed %= C * 2 - 2;

	board[s.r][s.c] = -1;

	while (speed--) {

		// 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
		if (d == 1 && s.r == R) d = 0;
		if (d == 0 && s.r == 1) d = 1;
		if (d == 2 && s.c == C) d = 3;
		if (d == 3 && s.c == 1) d = 2;

		s.r += dy[d];
		s.c += dx[d];
	}

	s.dir = d + 1;
}

int findNearSharkIdx() {
	int mn = INT_MAX;
	int target = -1;

	for (int i = 1; i <= R; i++) {
		if (board[i][person_x] >= 0) return board[i][person_x];
	}

	return target;
}

void fishing() {

	// 낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다
	person_x = 0;


	// 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
	while (person_x <= C) {
		// 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
		person_x++;

		// 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다
		int target = findNearSharkIdx();

		// 잡을 수 있는 상어가 있는 경우
		if (target >= 0) {
			score += shark[target].size;
			// 상어를 잡으면 격자판에서 잡은 상어가 사라진다. = 상어 사망
			shark[target].live = false;
			board[shark[target].r][shark[target].c] = -1;
		}

		// 3. 상어가 이동한다.
		for (Shark& s : shark) {
			if (s.live == false) continue;
			moveShark(s);
		}

		// 상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다
		fightShark();

	}

}



int main(void) {

	scanf("%d %d %d", &R, &C, &M);

	memset(board, -1, sizeof(board));

	for (int i = 0; i < M; i++) {
		Shark s;
		scanf("%d %d %d %d %d", &s.r, &s.c, &s.speed, &s.dir, &s.size);
		shark.push_back(s);
		board[s.r][s.c] = i;
	}

	fishing();

	printf("%d", score);


	return 0;
}
