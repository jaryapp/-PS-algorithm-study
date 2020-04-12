#include <stdio.h>
#include <cstring>

using namespace std;

int main(void){

    int N,score,correct;
    char str[100];

    scanf("%d",&N);

    for(int i = 0; i < N; i++){
        score = 0;
        correct = 0;
        scanf("%s",str);
        int len = strlen(str);

        for(int i = 0; i < len; i++){
            if(str[i] == 'O'){
                correct++;
                score += correct;
            }
            else correct = 0;
        }

        printf("%d\n",score);
    }

    return 0;
}