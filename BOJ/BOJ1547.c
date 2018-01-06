#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int a,b;
    int p=1;
    while(n--){
        scanf("%d %d",&a,&b);
        if(a==p || b==p){
            if(a==p) p=b;
            else p=a;            
        }
    }
    printf("%d\n",p);
}