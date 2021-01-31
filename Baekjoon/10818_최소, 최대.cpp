#include <iostream>
#include <limits.h>  
using namespace std;

int main() {
	int N;
	int min = INT_MAX;
	int max = INT_MIN;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		int num;
		scanf("%d", &num);
		min = min < num ? min : num;
		max = max > num ? max : num;
	}
	printf("%d %d",min,max);
	
	return 0;
}