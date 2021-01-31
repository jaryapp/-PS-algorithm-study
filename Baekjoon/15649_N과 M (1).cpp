#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


int N,M;
vector<int> stack;

void print(){
	for(int i = 0; i < stack.size(); i++){
		printf("%d ",stack[i]);
	}
	printf("\n");
	
}

bool has(int num){
	for(int i = 0; i < stack.size(); i++){
		if(stack[i] == num) return true;
	}
	
	return false;
}


void suyeol(int num,int depth){
	if(depth > M){
		print();
		return;
	}
	for(int i = 1; i <= N; i++){
		if(has(i)) continue;
		stack.push_back(i);
		suyeol(i+1,depth+1);
		stack.pop_back();
	}
}

int main() {
	
	scanf("%d %d",&N,&M);
	suyeol(1,1);
	
	return 0;
}