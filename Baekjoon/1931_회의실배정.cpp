#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int,int>> schedule;
stack<pair<int,int>> room;

bool compare(pair<int,int> A, pair<int,int> B){
	if(A.first == B.first){
		return A.second < B.second;
	}
	
	return A.first < B.first;
}

int main() {
	
	int N;
	
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		int st,en;
		scanf("%d %d",&st,&en);
		schedule.push_back(make_pair(st,en));
	}
	
	sort(schedule.begin(),schedule.end(),compare);
	
	
	
	
	for(int i = 0; i < N; i++){
		//printf("%d %d\n",schedule[i].first,schedule[i].second);
		if(room.empty()){
			room.push(schedule[i]);
		}
		else{
			pair<int,int> top = room.top();
			if(top.second <= schedule[i].first){
				room.push(schedule[i]);
			}
			else if(top.second > schedule[i].second){
				room.pop();
				room.push(schedule[i]);
			}
		}
	}
	
	printf("%d",room.size());
	
	
	return 0;
}