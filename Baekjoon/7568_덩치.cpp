#include <iostream>
using namespace std;

#define MAX_N 50

int main() {
	
    // first : 몸무게, second : 키
	pair<int,int> body[MAX_N+1];
	int N;
	
	scanf("%d",&N);
	
	for(int i = 0 ; i < N; i++){
		scanf("%d %d",&body[i].first,&body[i].second);
	}
	for(int i = 0 ; i < N; i++){
		int rank = 1;
		for(int j = 0 ; j < N; j++){
			if(body[j].first > body[i].first && body[j].second > body[i].second) rank++;
		}
		printf("%d ",rank);
	}

	return 0;
}