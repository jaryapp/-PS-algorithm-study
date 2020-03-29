#include <stdio.h>

using namespace std;

typedef long long ll;

ll cache[201][201] = {0,};

ll dp(int n, int k){
    if(cache[n][k]) return cache[n][k];
    ll sum = 0;
    if(k == 1) return 1;
    for(int i = 0; i <= n; i++){
        sum += dp(n-i,k-1);
    }
    
    return cache[n][k] = sum % 1000000000;
    
}

int main(void){
    
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    printf("%lld",dp(N,K));
    

    return 0;
}