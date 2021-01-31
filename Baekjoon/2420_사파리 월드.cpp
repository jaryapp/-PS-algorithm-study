#include <stdio.h>
#include <cstdlib>

using namespace std;

int main(void){
    
    long long a,b;
    
    scanf("%lld %lld",&a,&b);
    
    printf("%lld",abs(a-b));
    
    return 0;
}