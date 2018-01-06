#include <stdio.h>

int main(void){
    int max=0;
    int s=0;
    int a=4;
    int b,c;
    while(a--){
        scanf("%d %d",&b,&c);
        s=c-b;
        max=max>max+s?max:max+s;
    }
    printf("%d\n",max);
}