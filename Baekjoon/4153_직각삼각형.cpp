#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	
	while(true){
		int arr[3];
		
		scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
		
		if(!(arr[0] && arr[1] && arr[2])) break;
		
		sort(arr,arr+3);
		
		bool triangle = arr[2] * arr[2] == (arr[0]*arr[0] + arr[1]*arr[1]);
		
		if(triangle) printf("right");
		else printf("wrong");
		
		printf("\n");
		
	}
	
	return 0;
}