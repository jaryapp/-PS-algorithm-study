#include <iostream>
using namespace std;

int main() {
	
	int N;
	int a,b;
	
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		scanf("%d %d",&a,&b);
		int num = 1;
		for(int k = 0; k < b; k++){
			num = (num*a)%10;
		}
		if(num == 0) num = 10;
		printf("%d\n",num);
	}
	
	return 0;
}