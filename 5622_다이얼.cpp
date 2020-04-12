#include <stdio.h>
#include <cstring>
using namespace std;

int main(void){

    int dial[] = {
        2,2,2,   // ABC
        3,3,3,   // DEF
        4,4,4,   // GHI
        5,5,5,   // JKL
        6,6,6,   // MNO
        7,7,7,7, // PQRS
        8,8,8,   // TUV
        9,9,9,9  // WXYZ
    };

    char str[20];

    scanf("%s",str);

    int len = strlen(str);

    int num = 0;
    for(int i = 0; i < len; i++){
        num += dial[str[i]-'A'];
    }

    num += len;

    printf("%d",num);

    return 0;
}