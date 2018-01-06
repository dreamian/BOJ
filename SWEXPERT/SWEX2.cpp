#include <cstdio>
#include <cmath>
#define mod 1000000007
typedef long long ll;

using namespace std;

ll mul(ll x,ll y,ll p){
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

ll F(ll n,ll r){   // 중복 조합의 계산 + 페르마 소정리
    ll t1=1;
    ll t2=1;
    for(int i=1;i<=n;i++){
        t1*=i;
        t1%=mod;
    }
    for(int i=1;i<=(n-r);i++){
        t2*=i;
        t2%=mod;
    }
    for(int i=1;i<=r;i++){
        t2*=i;
        t2%=mod;
    }
    t2=mul(t2,mod-2,mod);
    t2%=mod;
    ll a=(t1*t2)%mod;

    return a;
}


int main(){
    int t;
    scanf("%d",&t);
    ll ans;
    for(int test=1;test<=t;test++){
        ans=0;
        int n,x;
        ll d;
        scanf("%d%lld%d",&n,&d,&x);

        ll term_a=0;
        
        for(int i=0;i<=floor(n/x);i++){
            term_a+=pow(-1,i)*F(d,i)*F(n-i*x+d-1,d-1);
            term_a%=mod;
            if(term_a<0) term_a+=mod;
        }
        
        if(x==1) term_a=0;
        if(x<(double)1+n/d) term_a=0;

        printf("#%d %lld\n",test,term_a);
    }
}