#include <iostream>
using namespace std;

#define MAX_N 100

int main() {
	int N,M;
	int card[MAX_N+1];
	
	scanf("%d %d",&N,&M);
	
	for(int i = 0; i < N; i++) scanf("%d",&card[i]);
	
	int mx = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			for(int k = j+1; k < N; k++){
				int sum = card[i] + card[j] + card[k];
				if(sum <= M && sum > mx){
					mx = sum;
				}
			}
		}
	}
	
	printf("%d",mx);
	
	return 0;
}