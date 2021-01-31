#include <iostream>
using namespace std;

#define MAX_SIZE 128

int map[MAX_SIZE+1][MAX_SIZE+1] = {0,};

pair<int,int> getColor(pair<int,int> paper){
	if(paper.first == 0) return make_pair(0,1);
	if(paper.second == 0) return make_pair(1,0);
	return paper;
}

// return first:WHITE second:BLUE
pair<int,int> getPaper(pair<int,int> from, pair<int,int> to,int size){
	
	/*
	for(int i = 0; i < size/2; i++){
		printf(" ");
	}
	
	printf("(%d,%d) ~ (%d,%d)\n",from.first,from.second,to.first,to.second);*/
	
	pair<int,int> paper;
	paper.first = 0;
	paper.second = 0;
	if(from.first == to.first && from.second == to.second){
		if(map[from.second][from.first] == 0){
			paper.first = 1;
			paper.second = 0;
		}
		else{
			paper.first = 0;
			paper.second = 1;
		}
		return paper;
	}
	
	size = size/2;
	
	
	pair<int,int> UL;
	pair<int,int> DL;
	pair<int,int> UR;
	pair<int,int> DR;
	
	UL = getPaper(from,make_pair(from.first+size-1,from.second+size-1),size);
	
	DL = getPaper(make_pair(from.first,from.second+size),make_pair(from.first+size-1,to.second),size);
	
	UR = getPaper(make_pair(from.first+size,from.second),make_pair(to.first,from.second+size-1),size);
	
	DR = getPaper(make_pair(from.first+size,from.second+size),to,size);
	
	paper.first += UL.first;
	paper.second += UL.second;
	
	paper.first += DL.first;
	paper.second += DL.second;
	
	paper.first += UR.first;
	paper.second += UR.second;
	
	paper.first += DR.first;
	paper.second += DR.second;
	
	return getColor(paper);
	
}

int main() {
	
	int N;
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	pair<int,int> paper = getPaper(make_pair(1,1),make_pair(N,N),N);
	printf("%d\n%d",paper.first,paper.second);
	
	
	return 0;
}