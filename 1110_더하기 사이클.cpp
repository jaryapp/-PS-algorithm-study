#include <stdio.h>
#include <cstring>
using namespace std;

int main(void){

    int N;
    int cnt = 0;
    scanf("%d",&N);
    int next = N;
    while(true){
        int a = next/10;
        int b = next%10;
        int sum = a+b;
        next = b*10+sum%10;
        cnt++;
        if(next == N) break;
    }

    printf("%d",cnt);

    return 0;
}