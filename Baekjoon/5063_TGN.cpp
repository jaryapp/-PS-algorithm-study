#include <iostream>
#include <limits.h>
using namespace std;

int main() {

    int N;

    scanf("%d",&N);

    for(int i = 0; i < N; i++){
        int r,e,c;
        scanf("%d %d %d",&r,&e,&c);
        if(e-c > r) printf("advertise");
        else if(e-c < r) printf("do not advertise");
        else printf("does not matter");
        printf("\n");
    }
	
	return 0;
}