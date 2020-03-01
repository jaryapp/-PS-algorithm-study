#include <iostream>
using namespace std;

bool end(int num){
	int six = 0;
	
	while(num){
		if(num%10 == 6) six++;
		else six = 0;
		if(six == 3) return true;
		num/=10;
	}
	
	return false;
}


int main() {
	
	int N;
	
	scanf("%d",&N);
	
	int num = 666;
	
	while(true){
		if(end(num)){
			//printf("%d\n",num);
			N--;
		}
		if(N == 0) break;
		num++;
	}
	
	printf("%d",num);
	
	
	return 0;
}