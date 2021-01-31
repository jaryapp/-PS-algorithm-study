#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100002

vector<int> connect[MAX_N];
int parent[MAX_N] = {0,};

void setParent(int node){
	//printf("%d\n",node);
	for(int i = 0; i < connect[node].size(); i++){
		//printf("%d %d\n",node,connect[node][i]);
		if(parent[connect[node][i]] == 0){
			parent[connect[node][i]] = node;
			setParent(connect[node][i]);
		}
	}
}

int main() {
	
	int N;
	
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		//printf("%d %d\n\n",a,b);
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	parent[1] = 1;
	
	setParent(1);
	
	for(int i = 2; i <= N; i++){
		printf("%d\n",parent[i]);
	}
	
	return 0;
}