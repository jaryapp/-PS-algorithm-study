/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int N,C;
    
    scanf("%d",&C);
    
    for(int t = 0; t < C; t++){
        scanf("%d",&N);
        int sum = 0;
        double avg;
        int student[1003];
        for(int i = 0; i < N; i++){
            scanf("%d",&student[i]);
            sum += student[i];
        }
        avg = sum/N;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(avg < student[i]) cnt++;
        }
       printf("%.3lf%\n",(double)cnt/N*100);
    }

    return 0;
}
