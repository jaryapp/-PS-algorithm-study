#include <iostream>
using namespace std;

int main() {
	
	
	int A,B,C;
	
	scanf("%d %d %d",&A,&B,&C);
	
	if(C > B){
		printf("%d",A/(C-B)+1);
	}
	else printf("-1");
	
	return 0;
}