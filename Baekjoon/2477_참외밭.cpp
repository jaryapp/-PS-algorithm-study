#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ll K;
	ll arr[7];
	ll maxWidth = 0;
	ll maxHeight = 0;
	ll holeWidth;
	ll holeHeight;
	// 시작 방향 0:가로 1:세로
	bool startDir = 1;
	scanf("%lld",&K);
	
	for(int i = 0; i < 6; i++){
		ll dir,length;
		scanf("%lld %lld",&dir,&length);
		if(i == 0){
			startDir = (dir-1)/2;
		}
		if(dir <= 2){
			maxWidth = max(maxWidth,length);
		}
		else if(dir <= 4){
			maxHeight = max(maxHeight,length);
		}
		arr[i] = length;
	}
	
	int cnt = 0;
	
	for(int i = 0; i <6; i+=2){
			// 세로 시작
			if(startDir){
				if(arr[i] != maxHeight && arr[i+1] != maxWidth){
					holeHeight = arr[i];
					holeWidth = arr[i+1];
					cnt++;
				}
			}
			else{
				if(arr[i] != maxWidth && arr[i+1] != maxHeight){
					holeHeight = arr[i+1];
					holeWidth = arr[i];
					cnt++;
				}
			}
	}
	
	// 큰거 두개가 한번에 묶였으경우
	if(cnt >= 2){
		arr[6] = arr[0];
		startDir = !startDir;
		for(int i = 1; i <= 6; i+=2){
			// 세로 시작
			if(startDir){
				if(arr[i] != maxHeight && arr[i+1] != maxWidth){
					holeHeight = arr[i];
					holeWidth = arr[i+1];
				}
			}
			else{
				if(arr[i] != maxWidth && arr[i+1] != maxHeight){
					holeHeight = arr[i+1];
					holeWidth = arr[i];
				}
			}
		}
	}
	
	//printf("%d %d %d %d\n",maxWidth,maxHeight,holeWidth,holeHeight);
	
	printf("%lld",(maxWidth*maxHeight-(holeWidth*holeHeight))*K);

	
	
	
	return 0;
}