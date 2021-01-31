#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Pos {
public:
	int y;
	int x;
};

vector<Pos> virus;
vector<Pos> space;
int map[10][10];
bool virus_map[10][10] = { false, };
int N, M;
int mx = 0;

void getShowVirusMap() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", virus_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}

int getSafe(){
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus_map[i][j] == 0 && map[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void spred(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return;
	if (map[y][x] == 1) return;
	if (virus_map[y][x] != 0) return;

	virus_map[y][x] = 2;

	spred(y + 1, x);
	spred(y, x+1);
	spred(y -1, x);
	spred(y , x-1);
}


int main(void) {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back({ i, j });
			}
			else if (map[i][j] == 0) {
				space.push_back({ i,j });
			}
		}
	}

	int os = space.size();
	int vs = virus.size();

	for (int i = 0; i < os; i++) {
		for (int j = i + 1; j < os; j++) {
			for (int k = j + 1; k < os; k++) {
				Pos w1 = space[i];
				Pos w2 = space[j];
				Pos w3 = space[k];

				map[w1.y][w1.x] = 1;
				map[w2.y][w2.x] = 1;
				map[w3.y][w3.x] = 1;
				
				memset(virus_map, 0, sizeof(virus_map));

				for (int v = 0; v < vs; v++) {
					Pos v1 = virus[v];
					spred(v1.y, v1.x);
				}

				//getShowVirusMap();
				int safe = getSafe();

				mx = safe > mx ? safe : mx;

				map[w1.y][w1.x] = 0;
				map[w2.y][w2.x] = 0;
				map[w3.y][w3.x] = 0;
			
			}
		}
	}

	printf("%d",mx);


	return 0;
}