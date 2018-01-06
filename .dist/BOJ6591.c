#include <stdio.h>
typedef long long ll;

int main(void){
    while(1){
        ll n,m;
        ll ans=1;
        scanf("%lld %lld",&n,&m);
        if(m>n/2) {m=n-m;}
        if(m==0 && n==0) break;
        else{
            ll cnt=m;
            for(;cnt>=1;cnt--){
                ans*=n;
                n--;
                while(m!=0 && ans%m==0){
                    ans/=m;
                    m--;
                }

            }

            printf("%lld\n",ans);

        }

    }
}