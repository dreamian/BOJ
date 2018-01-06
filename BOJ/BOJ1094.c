#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int ans=0;
    while(n!=0){
        ans+=n%2;
        n/=2;
    }
    printf("%d\n",ans);
}