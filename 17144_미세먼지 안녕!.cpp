#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


using namespace std;

int map[51][51];
int T, R, C;
int fy, fx = -1;
int sy, sx;

void show() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int getSum() {

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				sum += map[i][j];
			}
		}
	}
	return sum;
}

bool isValidate(int y, int x) {
	if (y < 0 || x < 0 || y >= R || x >= C) return false;
	if (map[y][x] == -1) return false;

	return true;

}

void spread() {
	int dmap[51][51] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				int cnt = 0;
				int dust = map[i][j];
				if (isValidate(i, j + 1)) {
					dmap[i][j + 1] += dust / 5;
					map[i][j] -= dust / 5;
				}
				if (isValidate(i, j - 1)) {
					dmap[i][j - 1] += dust / 5;
					map[i][j] -= dust / 5;
				}
				if (isValidate(i+1, j)) {
					dmap[i+1][j] += dust / 5;
					map[i][j] -= dust / 5;
				}
				if (isValidate(i-1, j)) {
					dmap[i-1][j] += dust / 5;
					map[i][j] -= dust / 5;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1) {
				map[i][j] += dmap[i][j];
			}
		}
	}

}

void blowFirstWind() {
	int dy[] = {-1,0,1,0};
	int dx[] = { 0,1,0,-1 };

	//int by = sy;
	//int bx = sx;
	int y = fy + dy[0];
	int x = fx + dx[0];
	int by = y;
	int bx = x;


	int i = 0;
	while(y != fy || x != fx){
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (ty < 0 || ty > fy || tx < 0 || tx >= C) i++;
		//if (i == 4)break;
		y += dy[i];
		x += dx[i];
		if (map[y][x] == -1) map[by][bx] = 0;
		else if(map[by][bx] != -1) map[by][bx] = map[y][x];
		by = y;
		bx = x;
	} 

}

void blowSecondWind() {
	int dy[] = { 1,0,-1,0 };
	int dx[] = { 0,1,0,-1 };

	//int by = sy;
	//int bx = sx;
	int y = sy + dy[0];
	int x = sx + dx[0];
	int by = y;
	int bx = x;

	int i = 0;
	while (y != sy || x != sx) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (ty < sy || ty >= R || tx < 0 || tx >= C) i++;
		//if (i == 4)break;
		y += dy[i];
		x += dx[i];
		if (map[y][x] == -1) map[by][bx] = 0;
		else if (map[by][bx] != -1) map[by][bx] = map[y][x];
		by = y;
		bx = x;
	}

}

int main(void) {


	scanf("%d %d %d", &R, &C, &T);


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				if (fx == -1) {
					fy = i;
					fx = j;
				}
				else {
					sy = i;
					sx = j;
				}
			}
		}
	}

	for (int t = 0; t < T; t++) {
		spread();
		//show();
		blowFirstWind();
		//show();
		blowSecondWind();
		//show();
	}

	printf("%d", getSum());

	


	return 0;
}