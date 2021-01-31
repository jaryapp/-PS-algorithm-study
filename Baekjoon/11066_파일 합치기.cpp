#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cache[502][502];
int nu[502][502];
vector<int> files;

int n(int a, int b){
	if(a == b) return 0;
	if(b == a + 1) return files[a] + files[b];
	return nu[a][b];
}

int f(int a, int b){
	if(a == b) return files[a];
	if(cache[a][b]) return cache[a][b];
	
	int mn = 2000000000;
	
	
	for(int k = a; k < b; k++){
		int n1 = f(a,k);
		int n2 = f(k+1,b);
		if(n(a,k) + n(k+1,b) + n1 + n2 < mn){
			cache[a][b] = n1 + n2;
			mn = n(a,k) + n(k+1,b) + n1 + n2;
			nu[a][b] = mn;
		}
	}
	
	return cache[a][b];
	
}


int main() {
	
	int T;
	

	files.resize(502);
	
	scanf("%d",&T);
	
	for(int t = 0; t < T; t++){
		int K;
		scanf("%d",&K);
		for(int k = 0; k < K; k++){
			scanf("%d",&files[k]);
		}
		
		for(int i = 0; i < 502; i++){
			fill_n(cache[i],502,0);
		}
		f(0,K-1);
		printf("%d\n",nu[0][K-1]);
		
	}
	
	return 0;
}