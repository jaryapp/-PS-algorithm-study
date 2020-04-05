#include <iostream>
#include <cstring>
using namespace std;


int main() {

    int mx = 0;
    int alpha['z'+2] = {0,};
    char str[5002];


    while (!cin.eof()) {    //EOF를 만날때까지 무한 입력
        cin.getline(str,5002);

        int len = strlen(str);

        for(int i = 0; i < len; i++){
            alpha[str[i]]++;
            if(str[i] >= 'a' && str[i] <= 'z' && mx <= alpha[str[i]]){
                mx = alpha[str[i]];
            }
        }
    }



    for(char i = 'a'; i <= 'z'; i++){
        if(mx == alpha[i]) printf("%c",i);
    }
	

	return 0;
}