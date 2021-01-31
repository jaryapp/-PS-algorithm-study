#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> pos;


int compare(pair<int,int> a, pair<int,int> b){
	
	if(a.first == b.first){
		return a.second < b.second;
	}else{
		return a.first < b.first;
	}
	
}

int main() {
	
	int N;
	
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		pair<int,int> xy;
		scanf("%d %d",&xy.first,&xy.second);
		pos.push_back(xy);
	}
	
	sort(pos.begin(),pos.end(),compare);
	
	for(int i = 0; i < N; i++){
		printf("%d %d\n",pos[i].first,pos[i].second);
	}
	
	
	return 0;
}