#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coin;

int cnt = 0;
int n,k;

int cache[2][10002]= {0,};


int main() {
	
	scanf("%d %d",&n,&k);
	
	coin.push_back(0);
	
	for(int i = 1; i <= n; i++){
		int num;
		scanf("%d",&num);
		coin.push_back(num);
		// cache[i][0] = 1;
	}
	
	sort(coin.begin(),coin.end());
	
	for(int c = 1; c <= n; c++){
		for(int K = 1; K <= k; K++){
			int dist = K-coin[c];
			if(dist < 0){
				cache[c%2][K] = cache[(c-1)%2][K];
				continue;
			}
			else if(dist == 0) cache[c%2][0] = 1;
			cache[c%2][K] = (cache[c%2][dist] + cache[(c-1)%2][K]);
		}
	}
	
	printf("%d", cache[n%2][k]);

	
	return 0;
}