#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

class Doc{
public:
    bool isTarget;
    int grade;
    Doc(int g,bool t){
        grade = g;
        isTarget =t;
    }
};

vector<Doc> q;


void print_queue(){
    
    int count = 0;
    
    while(q.size()){
        Doc f = q.front();
        bool good = true;
        q.erase(q.begin());
        count++;
        for(int i = 0;i<q.size();i++){
            if(f.grade < q[i].grade){
                q.push_back(f);
                good = false;
                count--;
                break;
            }
        }
        if(good && f.isTarget){
            cout << count << endl;
            return;
        }
    }
}

int main(void){
    
    //freopen("input.txt","r",stdin); // 제출시 주석처리
    
    int testcase,N,M;
    
    cin >> testcase;
    
    for(int i = 0; i < testcase; i++){
        cin >> N >> M;
        for(int k = 0; k < N; k++){
            int n;
            bool t = false;
            cin >> n;
            if(k==M) t = true;
            Doc *doc = new Doc(n,t);
            q.push_back(*doc);
            
        }
        print_queue();
        q.clear();
    }
    
    return 0;
}