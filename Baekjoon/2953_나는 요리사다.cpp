/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    
    int a,b,c,d;
    
    int mx = 0;
    int num = 0;
	
	for(int i = 1; i <= 5; i++){
	    scanf("%d %d %d %d",&a,&b,&c,&d);
	    int sum = a+b+c+d;
	    if(mx < sum){
	        mx = sum;
	        num = i;
	    }
	}
	printf("%d %d",num,mx);
	
	return 0;
}