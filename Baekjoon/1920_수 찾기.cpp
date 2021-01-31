#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
    
    int N;
    
    scanf("%d",&N);
    
    int arr[100002];
    
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    sort(arr,arr+N);

    
    int M;
    
    scanf("%d",&M);
    
    for(int i = 0; i < M; i++){
        int num;
        scanf("%d",&num);
        printf("%d\n",binary_search(arr,arr+N,num));
    }
    

    
    return 0;
}