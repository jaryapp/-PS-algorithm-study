#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Bus{
public:
	int s;
	int e;
	int t;
};

vector<Bus> bus;
int dist[502] = {0,};


int main() {
	
	int N,C;
	scanf("%d %d",&N,&C);
	
	
	for(int i = 0; i < C; i++){
		int s,e,t;
		scanf("%d %d %d",&s,&e,&t);
		bus.push_back({s,e,t});
	}
	
	fill_n(dist,502,INT_MAX);
	dist[1] = 0;
	
	bool hasUpdate;
	for(int i = 0; i <= N; i++){
		hasUpdate = false;
		for(int k = 0; k < C; k++){
			Bus b = bus[k];
			if(dist[b.s] == INT_MAX) continue;
			if(dist[b.e] > dist[b.s] + b.t){
				dist[b.e] = dist[b.s] + b.t;
				hasUpdate = true;
			}
		}
	}
	
	if(hasUpdate){
		printf("-1");
	}
	else{
		for(int i = 2; i <= N; i++){
			if(dist[i] == INT_MAX) printf("-1\n");
			else printf("%d\n",dist[i]);
		}
	}
	
	return 0;
}

// https://ratsgo.github.io/data%20structure&algorithm/2017/11/27/bellmanford/