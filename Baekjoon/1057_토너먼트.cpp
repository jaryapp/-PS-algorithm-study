#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    int N,K,H;

    scanf("%d %d %d",&N,&K,&H);

    int round = 0;
    while(true){
        round++;
        K = K/2 + K%2;
        H = H/2 + H%2;
        if(K == H) break;
    }

    printf("%d",round);

    return 0;
}