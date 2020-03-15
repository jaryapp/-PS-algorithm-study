#include <iostream>
#include <string.h>

int main(void){
    
    char str[1000002];
    int cnt[200] = {0,};
    char c;
    
    scanf("%s",str);
    
    int mx = 0;
    int len = strlen(str);
    
    for(int i = 0; i < len; i++){
        char a = str[i];
        if(a >= 'a') a -= ('a' - 'A');
        cnt[a]++;
        if(mx < cnt[a]){
            mx = cnt[a];
            c = a;
        }
        else if(mx == cnt[a]){
            c = '?';
        }
    }
    
    printf("%c",c);
    
    
    
    
    
    return 0;
}