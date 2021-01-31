#include <stdio.h>

int main(void)
{
    int X,N;

    scanf("%d %d",&N,&X);

    for(int i = 0; i < N; i++){
        int num;
        scanf("%d",&num);
        if(num < X) printf("%d ",num);
    }

    return 0;
}