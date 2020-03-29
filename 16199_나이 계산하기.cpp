#include <stdio.h>
#include <algorithm>

int main(void){
    
    int man,sae,yeon;
    
    int y,m,d;
    int y2,m2,d2;
    scanf("%d %d %d",&y,&m,&d);
    scanf("%d %d %d",&y2,&m2,&d2);
    
    if(m2 > m){
        man = y2-y;
    }
    else if(m2 == m && d2 >= d){
         man = y2-y;
    }
    else  man = y2-y-1;
    
    sae = y2 - y +1;
    yeon = y2 - y;
    
    printf("%d\n%d\n%d",man,sae,yeon);
    
   
    return 0;
}