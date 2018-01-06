#include <stdio.h>
typedef long long ll;

ll dp[2000003]={0,};

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

ll fac(ll n,ll p){
    ll ans=1;
    if(dp[n]!=0) return dp[n];
    else{
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=p;
        dp[i]=ans;
    }
    }

    return ans;
}

int main(void){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll p=1000000007;
    ll t1, t2, t3;
    t1=fac(n+k+2,p);
    t2=fac(k+1,p);
    t3=fac(n+1,p);
    t2=(t2*t3)%p;

    ll t4=mul(t2,p-2,p);
    t4%=p;
    ll ans;
    ans=t1*t4;
    ans%=p;
    printf("Case #%d\n",i);
    printf("%lld\n",ans-1);
    }

}