#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>


using namespace std;

int r, c, k;
int A[105][105];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int szRow = 3;
int szCol = 3;


void R() {

	szCol = 0;

	for (int i = 1; i <= 100; i++) {
		map<int, int> cnt;
		for (int j = 1; j <= 100; j++) {
			if (A[i][j] == 0) continue;
			cnt[A[i][j]]++;
			A[i][j] = 0;
		}
		
		vector<int> h[103];

		for (auto a = cnt.begin(); a != cnt.end(); a++) {
			h[a->second].push_back(a->first);
		}

		int col = 1;

		for (int t = 1; t <= 100; t++) {
			for (auto a = h[t].begin(); a != h[t].end(); a++) {
				A[i][col] = *a;
				A[i][col+1] = t;
				col += 2;
				if (col > szCol) szCol = col;
				if(col > 100) break;
			}
		}


	}

}

void C() {

	szRow = 0;
	for (int i = 1; i <= 100; i++) {
		map<int, int> cnt;
		for (int j = 1; j <= 100; j++) {
			if (A[j][i] == 0) continue;
			cnt[A[j][i]]++;
			A[j][i] = 0;
		}

		vector<int> h[103];

		for (auto a = cnt.begin(); a != cnt.end(); a++) {
			h[a->second].push_back(a->first);
		}

		int row = 1;

		for (int t = 1; t <= 100; t++) {
			for (auto a = h[t].begin(); a != h[t].end(); a++) {
				A[row][i] = *a;
				A[row+1][i] = t;
				row += 2;
				if (row > szRow) szRow = row;
				if(row > 100) break;
			}
		}


	}

}

int main(void) {


	scanf("%d %d %d", &r, &c, &k);

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int t = 0;

	while (true) {
		if (A[r][c] == k) break;
		if (szRow >= szCol) {
			R();
		}
		else C();

		t++;
		if (t > 100) {
			printf("-1");
			return 0;
		}
	}

	printf("%d", t);
	return 0;

}