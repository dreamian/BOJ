#include <stdio.h>
typedef long long ll;

int main(void){
    ll n,k;
    ll ans_a=1;
    ll ans_b=1;
    scanf("%lld %lld",&n,&k);
    if(k==0) {printf("1\n");}
    else{
        for(int i=0;i<k;i++){
            ans_a*=(n-i);
            ans_b*=(k-i);
        }
        printf("%lld\n",ans_a/ans_b);
    }
    
}