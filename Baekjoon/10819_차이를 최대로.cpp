#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

vector<int> v;

bool visited[8] = {0,};
int N;
int arr[8];

int mx = 0;
    

void check(int depth){
    
    if(depth >= N){
        int sum = 0;
        for(int i = 0; i < N-1 ; i++){
            sum += abs(v[i] - v[i+1]);
        }
        mx = sum > mx ? sum : mx;
    }
    
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        check(depth+1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(void){
    
    scanf("%d",&N);
    
    for(int i = 0; i < N ; i++){
        scanf("%d",&arr[i]);
    }
    
    check(0);
    
    printf("%d",mx);
    
    
    

    
    return 0;
}