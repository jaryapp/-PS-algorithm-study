#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include<cmath>

#define MAX_NUM 500001
#define MIN_NUM -500001

using namespace std;

vector<int> arr;

int getRange(){
    
    int max_num = MIN_NUM;
    int min_num = MAX_NUM;

    for(int i: arr) {
        max_num = i > max_num ? i : max_num;
        min_num = i < min_num ? i : min_num;
    }

    return max_num - min_num;
}


int getMode(){
    int max_cnt = 1;
    int cnt = 1;
    int bfr = arr[0];
    vector<int> arr_mode;
    arr_mode.push_back(arr[0]);
    for(int i = 0; i < arr.size(); i++){
        if(i==0) continue;
        int num = arr[i];
        if(num != bfr){
            if(cnt > max_cnt){
                arr_mode.clear();
                arr_mode.push_back(bfr);
                max_cnt = cnt;
            }
            else if(cnt==max_cnt){
                if(arr[0] != bfr) arr_mode.push_back(bfr);
            }
            cnt = 1;
            bfr = num;
        }
        else cnt++;
        
        if(i == arr.size()-1){
            if(cnt > max_cnt){
                arr_mode.clear();
                arr_mode.push_back(num);
                max_cnt = cnt;
            }
            else if(cnt==max_cnt){
                if(arr[0] != num) arr_mode.push_back(num);
            }
        }
        
    }

    sort(arr_mode.begin(), arr_mode.end());
    
    if(arr_mode.size()>=2){
        return arr_mode[1];
    }
    else{
        return arr_mode[0];
    }
}

int getMedian(){
    int md = (int)arr.size()/2;
    if(arr.size()%2==1){
        return arr[md];
    }
    else{
        double sum = arr[md-1] + arr[md];
        double avg = sum/2;
        return floor(avg+0.5);
    }
}

int getArithmeticMean(){
    double sum = 0;
    for(int i: arr) {
        sum += i;
    }
    
    double avg = sum/arr.size();
    return floor(avg+0.5);
    
    return avg;
}

int main(void){
    
    //freopen("input.txt","r",stdin); // 제출시 주석처리
    
    int N,k;
    
    cin >> N;
    
    for(int n = 0; n < N; n++){
        cin >> k;
        arr.push_back(k);
    }
    
    sort(arr.begin(), arr.end());
    
    printf("%d\n%d\n%d\n%d",getArithmeticMean(),getMedian(),getMode(),getRange());
    
    return 0;
}