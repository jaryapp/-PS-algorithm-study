#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

int main(void){
    
    int N;
    int cache[1002] = {0,};
    
    scanf("%d",&N);
    

    for(int i = 1; i <= N; i++){
        scanf("%d",&cache[i]);
        for(int k = i; k >= i/2; k--){
            cache[i] = min(cache[i],cache[k] + cache[i-k]);
        }
    }
    
    printf("%d",cache[N]);

    
    return 0;
}