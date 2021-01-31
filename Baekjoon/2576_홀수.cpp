#include <iostream>
#include <limits.h>
using namespace std;

int main() {

    int sum = 0;
    int min = INT_MAX;

    for(int i = 0; i < 7; i++){
        int num;
        scanf("%d",&num);
        if(num % 2 == 1){
            min = min > num ? num : min;
            sum += num;
        }
    }

    if(sum != 0) printf("%d\n%d",sum,min);
    else printf("-1");
	
	
	return 0;
}