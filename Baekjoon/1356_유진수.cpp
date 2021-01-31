#include <iostream>
#include <cstring>
using namespace std;


int main() {

    char N[100];

    scanf("%s",&N);

    bool ujin = false;

    int len = strlen(N);

    if(len > 1){
        int left = 1;
        int right = 1;
        for(int i = 0; i < len-1; i++){
            left *= (N[i]-'0');
            right = 1;
            for(int j = i+1; j < len; j++){
                right *= (N[j]-'0');
            }
            if(left == right){
                ujin = true;
                break;
            }
        }
    }

    if(ujin) printf("YES");
    else printf("NO");

	return 0;
}