#include <iostream>
#include <cstring>
#include <stdio.h>

int cnt[8] = {0,};
char turn[8][4] = {"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};

void cm(char* str){
//	printf("%s\n",str);
    for(int i = 0; i < 8; i++){
        if(strcmp(str,turn[i]) == 0){
            cnt[i]++;
            return;
        }
    }
}

int main(void){
    
    int P;
    
    //freopen("input.txt","r",stdin);
    
    scanf("%d",&P);
    
    for(int p = 0; p < P; p++){
        char result[42];
        scanf("%s",result);
        int len = strlen(result);
        
        for(int i = 0; i < len-2; i++){
            char str[4];
            strncpy(str,result+i,3);
            cm(str);
        }
        
        for(int i = 0; i < 8; i++){
            printf("%d ",cnt[i]);
            cnt[i] = 0;
        }
        printf("\n");
    }
    
    
    return 0;
}