#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alpha;
vector<char> all;
int cntMo = 0;
int cntJa = 0;
int L,C;

void dfs(int st, int depth){
    if(depth == L){
        if(cntMo >= 1 && cntJa >= 2){
            int size = alpha.size();
            for(int i = 0; i < size; i++){
                printf("%c",alpha[i]);
            }
            printf("\n");
        }
        return;
    }

    int all_size = all.size();
    for(int i = st; i < all_size; i++){
        char c = all[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            cntMo++;
        }
        else cntJa++;
        alpha.push_back(c);
        dfs(i+1,depth+1);
        alpha.pop_back();
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            cntMo--;
        }
        else cntJa--;
    }



	
}

int main() {
	
	
	scanf("%d %d",&L,&C);
	
	char c;
	for(int i = 0; i < C; i++){
		cin >> c;
        all.push_back(c);
	}
	
	sort(all.begin(),all.end());

    dfs(0,0);
	
	
	return 0;
}