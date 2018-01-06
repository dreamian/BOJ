#include <stdio.h>

long long arr[92];

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        if (i==0) {arr[i]=0;}
        else if (i==1) {arr[i]=1;}
        else arr[i]=arr[i-1]+arr[i-2];
    }

    printf("%lld\n",arr[n]);
    return 0;
}