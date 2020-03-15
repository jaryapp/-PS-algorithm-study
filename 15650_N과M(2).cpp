#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE	8

bool visited[MAX_SIZE + 1] = {0,};
vector<int> v;
int M,N;


void show(){
	for(int i = 0; i < N; i++){
		printf("%d ",v[i]);
	}
	printf("\n");
}


void dfs(int n, int cnt){
	if(cnt == N){
		show();
		return;
	}
	
	for(int i = n+1; i <= M; i++){
		if(!visited[i]){
			visited[i] = true;
			v.push_back(i);
			dfs(i,cnt+1);
			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	
	scanf("%d %d",&M,&N);
	
	dfs(0,0);
	
	return 0;
}