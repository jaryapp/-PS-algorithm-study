#include <iostream>
#include <algorithm>
using namespace std;

int getSum(int* arr, bool* visited){
	int sum = 0;
	for(int i = 0; i < 9; i++){
		if(visited[i]) continue;
		sum += arr[i];
	}
	
	return sum;
	
}

int main() {
	
	int* smaller =  new int[9];
	bool* visited = new bool[9];
	int sum;
	
	for(int i = 0; i < 9; i++){
		scanf("%d",&smaller[i]);
	}
	
	sort(smaller,smaller+9);
	
	
	for(int i = 0; i <= 9 - 2; i++){
		visited[i] = 1;
		for(int j = i + 1; j < 9; j++){
			visited[j] = 1;
			sum = getSum(smaller,visited);
			if(sum == 100) break;
			visited[j] = 0;
		}
		if(sum == 100) break;
		visited[i] = 0;
	}
	
	for(int i = 0; i < 9; i++){
		if(visited[i]) continue;
		printf("%d\n",smaller[i]);
	}
	
	return 0;
}