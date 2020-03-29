#include <iostream>
#include <cstring>

int main(void){
    
    char A[102];
    char B[102];
    char op;
    
    scanf("%s\n",A);
    scanf("%c",&op);
    scanf("%s",B);
    
    int lenA = strlen(A);
    int lenB = strlen(B);
    
    if(op == '*'){
        printf("1");
        for(int i = 0; i < lenA + lenB - 2; i++){
            printf("0");
        }
    }
    else if(op == '+'){
        int blen = lenA > lenB ? lenA : lenB;
        int slen = lenA < lenB ? lenA : lenB;
        
        
        if(blen != slen) printf("1");
        for(int i = 0; i < blen - slen - 1; i++){
            printf("0");
        }
        if(blen != slen) printf("1");
        if(blen == slen) printf("2");
        for(int i = 0; i < slen - 1; i++){
            printf("0");
        }
        
    }
    
    return 0;
}