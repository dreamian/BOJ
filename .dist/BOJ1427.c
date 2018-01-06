#include <stdio.h>

int main(void){
    long long int n;
    int bucket[10]={0};
    scanf("%lld",&n);

    if (n==0) {printf("%lld\n",n); return 0;}

    while(n!=0){
        bucket[n%10]+=1;
        n/=10;
    }
    int k=10;
    while(k--){
        while(bucket[k]--){
            printf("%d",k);
        }
    }
    printf("\n");
}