#include <iostream>
#include <vector>
using namespace std;

vector<int> set[1000002];
int parent[1000002];

int n;

void printParent(){
	for(int i = 0; i <= n; i++){
		printf("%d ",parent[i]);
	}
	printf("\n");
}

bool isSameParent(int a, int b){
	a = parent[a];
	b = parent[b];

	return a==b;
	
}

void hop(int a, int b){
	a = parent[a];
	b = parent[b];
	
	if(a == b) return;
	int sm = a > b ? b : a;
	int bi = a < b ? b : a;
	
	int len = set[bi].size();
	
	for(int i = 0; i < len; i++){
		set[sm].push_back(set[bi][i]);
		parent[set[bi][i]] = sm;
	}
	
	
}

int main() {
	
	int m;
	
	scanf("%d %d",&n,&m);
	
	for(int i = 0; i <= n; i++){
		parent[i] = i;
		set[i].push_back(i);
	}
	
	// printParent();
	
	for(int i = 0; i < m; i++){
		int a,b,c;
		scanf("%d %d %d",&c,&a,&b);
		if(c == 0) hop(a,b);
		else if(c == 1){
			printf("%s\n",isSameParent(a,b) ? "YES" : "NO");
		}
	}
	
	//printParent();
	
	
	return 0;
}