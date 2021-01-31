#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,char*>> member;

bool compare(pair<int,char*> a,pair<int,char*> b ){
	return a.first < b.first;
}

int main() {
	
	int N;
	
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		int age;
		char *name = new char[105];
		
		scanf("%d %s",&age,name);
		
		member.push_back(make_pair(age,name));
		
	}
	
	stable_sort(member.begin(),member.end(),compare);
	
	for(int i = 0; i < N; i++){
		auto a = member[i];
		printf("%d %s\n",a.first,a.second);
	}
	
	return 0;
}