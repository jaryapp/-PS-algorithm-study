#include <stdio.h>
int combination(int m, int n);

int dp[32][32] = {0,};

int main(void)
{
    int Tcase;
    int N, M;

    scanf("%d", &Tcase);

    for (int i = 0; i < Tcase; i++) {
        int total;
        scanf("%d %d", &N, &M);
        if (M - N == 0) total = 1;
        else{
            total = combination(M, N);
        }

        printf("%d\n", total);
    }

    return 0;
}

int combination(int n, int r) {
	if(dp[n][r]) return dp[n][r];
    if (n == r || r == 0) return 1; 
    else return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}