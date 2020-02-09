#include <iostream>
using namespace std;

int main() {
	
	int N;
	long long result = 1;
	
	scanf("%d",&N);
	
	for(int i = 2; i <= N; i++){
		result *= i;
	}
	
	printf("%lld",result);
	
	return 0;
}