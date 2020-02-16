#include <iostream>
using namespace std;

#define MAX_N 10+1

int main() {
	
	int N;
	int A[MAX_N];
	long K;
	
	scanf("%d %ld",&N,&K);
	
	for(int i = 0; i < N; i++){
		scanf("%d",&A[i]);
	}
	
	int cnt = 2147483647;
	
	//printf("%d",cnt);
	
	for(int j = 1; j <= N; j++){
		long m = K;
		int c = 0;
		for(int i = N-j; i >=0 ; i--){
			if(m>=A[i]){
				c += m/A[i];
				m %= A[i];
			}
		}
		cnt = min(cnt,c);
	}
	
	printf("%d",cnt);
	
	
	return 0;
}