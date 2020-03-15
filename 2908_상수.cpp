#include <iostream>

int main(void){
    
    int N1,N2;
    
    scanf("%d %d",&N1,&N2);
    
    int n1 = N1%10*100;
    n1 += (N1/10)%10*10;
    n1 += N1/100;
    
  int n2 = N2%10*100;
    n2 += (N2/10)%10*10;
    n2 += N2/100;
    
    
    printf("%d",n1 > n2 ? n1 : n2);
    
    return 0;
}