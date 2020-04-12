#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    vector<int> A;

    int N,M;

    scanf("%d %d",&N,&M);

    for(int i = 0; i < N+M; i++){
        int  num;
        scanf("%d",&num);
        A.push_back(num);
    }

    sort(A.begin(),A.end());

    for(int i = 0; i < N+M;i++){
        printf("%d ",A[i]);
    }

    return 0;
}