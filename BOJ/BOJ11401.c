#include <stdio.h>
typedef long long ll;

ll mul(ll x, ll y, ll p) {
    ll ans = 1;
    while (y > 0) {
        if (y%2 != 0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y/=2;
    }
    return ans;
}

int main(void){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll p=1000000007;
    ll t1=1,t2=1;
    ll ans=1;
    for(int i=1;i<=n;i++){
        t1*=i;
        t1%=p;
    }
    for(int i=1;i<=k;i++){
        t2*=i;
        t2%=p;
    }
    for(int i=1;i<=(n-k);i++){
        t2*=i;
        t2%=p;
    }

    ll t3=mul(t2,p-2,p);
    t3%=p;
    ans=t1*t3;
    ans%=p;
    printf("%lld\n",ans);

}