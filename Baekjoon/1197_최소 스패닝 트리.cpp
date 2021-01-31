#include <iostream>
#include <queue>

using namespace std;

class A{
public:
    long long a;
    long long b;
    long long c;

};


struct compare{
    bool operator()(A &a,A &b){
        return a.c>b.c;
    }
};




priority_queue <A ,vector<A>,compare> pq;

vector<pair<int,int>> graph[10002];

int main(void){
    
    int V,E;
    
    scanf("%d %d",&V,&E);
    
    int a,b,c;
    
    
    for(int i = 0; i < E; i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    
    bool visited[10002] = {0,};
    
    
    A k;
    
    int idx = 1;
    long long sum = 0;
    visited[1] = 1;
    int cnt = 1;
    while(cnt < V){
        
        for(auto it = graph[idx].begin(); it != graph[idx].end(); it++){
            k.a = idx;
            k.b = it->first;
            k.c = it->second;
            pq.push(k);
        }
        
        while(true){
            auto v = pq.top();
            pq.pop();
            if(visited[v.b]) continue;
            sum += v.c;
            idx = v.b;
            cnt++;
            visited[v.b] = true;
            break;
        }
    }
    
    printf("%lld",sum);

    
    
    
    
    return 0;
    
}