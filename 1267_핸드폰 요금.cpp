#include <stdio.h>

using namespace std;

int main(void){
    
    int N;
    
    scanf("%d",&N);
    
    int Y = 0;
    int M = 0;
    
    int cost;
    
    for(int i = 0; i < N; i++){
        scanf("%d",&cost);
        Y += (cost/30+1)*10;
        M += (cost/60+1)*15;
    }
    
    if(Y < M){
        printf("Y %d",Y);
    }
    else if(Y > M){
        printf("M %d",M);
    }
    else {
        printf("Y M %d",Y);
    }
    
    
    return 0;
}