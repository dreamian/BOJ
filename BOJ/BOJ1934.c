#include <stdio.h>
int GCD(int a,int b){
    if(b==0) return a;
    else return GCD(b,a%b);
}

int main(void){
    int a,b,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&a,&b);
    printf("%d\n",a*b/GCD(a,b));
    }
}
