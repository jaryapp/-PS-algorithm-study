#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){
    
    int N;
    
    scanf("%d",&N);
    
    int bag = -1;
    
    int five = 0;
    int cnt = 0;
    
    while(N >= five){
        int n = N-five;
        if(n%3 == 0){
            bag = n/3 + cnt;
        }
        cnt++;
        five+=5;
    }
    
    printf("%d",bag);
    

    
    return 0;
}