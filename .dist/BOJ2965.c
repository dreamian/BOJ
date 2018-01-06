#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    
    int d_1=b-a;
    int d_2=c-b;
    int ans=d_1>d_2?d_1:d_2;
    printf("%d\n",ans-1);
}