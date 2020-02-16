#include <iostream>
using namespace std;

#define MAX_N 1002

int N,M;
bool possible[MAX_N][MAX_N] = {0,};
bool visited[MAX_N] = {0,};
int arrWork[MAX_N] = {0,};
int cnt = 0;

bool match(int person){
	visited[person] = true;
	for(int i = 1; i <= M; i++){
		//printf("i%d %d %d\n",i,M,i<=M);
		if(possible[person][i]){
			if(visited[arrWork[i]]) continue;
			if(!arrWork[i] == 0){
				if(match(arrWork[i])) arrWork[i] = 0;
			}
			if(arrWork[i] == 0){
				//printf("%d -> %d\n",person,i);
				arrWork[i] = person;
				return true;
			}
		}
	}
	return false;
}

int main() {
	
	scanf("%d %d",&N,&M);
	
	for(int i = 1; i <= N; i++){
		int cntWork;
		scanf("%d",&cntWork);
		for(int j = 0; j < cntWork; j++){
			int work;
			scanf("%d",&work);
			possible[i][work] = true;
		}
		//printf("person %d\n",i);
		fill_n(visited,MAX_N,0);
		if(match(i)) cnt++;
	}
	
	printf("%d",cnt);
	
	return 0;
}