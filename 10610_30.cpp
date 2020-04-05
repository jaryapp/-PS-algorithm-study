#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {

    char N[100002];

    scanf("%s",N);

    int len = strlen(N);

    bool hasZero = false;
    long long sum = 0;
    for(int i = 0; i < len; i++){
        sum += (N[i]-'0');
        if(N[i] == '0') hasZero = true;
    }

    if(sum % 3 == 0 && hasZero){
        sort(N,N+len,greater<int>());
        printf("%s",N);
    }
    else printf("-1");
	
	return 0;
}