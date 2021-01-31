#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

vector<int> v;

int getLeftMax(int st, int en){
    if(st < en) return 0;
    int sum = 0;
    int mx = INT_MIN;
    for(int i = st; i >= en; i--){
        sum += v[i];
        if(sum > mx) mx = sum;
    }
    return mx;
}


int getMax(int st, int en){
    if(st > en) return 0;
    int sum = 0;
    int mx = INT_MIN;
    for(int i = st; i <= en; i++){
        sum += v[i];
        if(sum > mx) mx = sum;
    }
    return mx;
}

int main(void){
    int N,num;

    int answer = INT_MIN;

    scanf("%d",&N);

    int total = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&num);
        if(num <= 0){
            if(total > 0) v.push_back(total);
            v.push_back(num);
            total = 0;
        }
        else{
            total += num;
        }
    }

    if(total > 0) v.push_back(total);

    int len = v.size();

    if(len == 1){
    	printf("%d",v[0]);
    	return 0;
    }
    
    for(int i = 0; i < len; i++){
        if(v[i] > answer) answer = v[i];
        if(v[i] < 0){
            int left = getLeftMax(i-1,0);
            int right = getMax(i+1,len-1);
            //  printf("%d %d %d\n",v[i],left,right);
            if(left+right > answer) answer = left+right;
        }
    }

    printf("%d",answer);
    
    return 0;


}