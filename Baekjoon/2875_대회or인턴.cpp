#include <stdio.h>

int main(void){
    
    int N,M,K;
    
    scanf("%d %d %d",&N,&M,&K);
    
    while(K>0){
        if(N > 2*M){
            N--;
        }
        else M--;
        K--;
    }
    
    printf("%d",N/2 > M ? M : N/2);
    
    return 0;
}