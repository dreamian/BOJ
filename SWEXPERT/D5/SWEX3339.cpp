// input으로 들어오는 소수는 ll 형으로 받았어야 했다.
// 제한된 조건 내의 소수의 범위가 10^12까지 이므로 배열이나 vector로 check하는 형식으로는 접근 불가
// pair를 이용해 문제 풀이, 이 때 pair는 소인수 분해를 한 후의 소수들을 담는 컨테이너
// 크기가 일정하지 않기 때문에 resize를 하는 방식으로 계속 크기를 키워나감.
// 표현하는 수의 범위가 매우 크기 때문임.

#include <bits/stdc++.h>
#include <memory.h>

using namespace std;
typedef long long ll;
const ll mod = pow(10,9)+7;

ll mul(ll x, ll power){
    ll ans=1;
    while(power>0){
        if(power%2!=0){
            ans*=x;
            ans%=mod;
        }
        x*=x;
        x%=mod;
        power/=2;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);

    for(int test=1;test<=t;test++){
        ll n=0,m=0;
        ll ans=1;
        bool flag=false;
        scanf("%lld%lld",&n,&m);
        if(n==1) flag=true;
        else{
        double tmp=sqrt(n);
        int tmp_2=sqrt(n);
        while(tmp==tmp_2){
            if(tmp==double(tmp_2)) {n=sqrt(n); m*=2;}
            tmp=sqrt(n);
            tmp_2=sqrt(n);
        }
        }
        // 소인수 분해 과정
        // queue는 소수를 저장
        // prime은 소인수의 지수를 저장
        // 원래대로 라면 소수를 먼저 구해야 하나, 시간 복잡도를 고려
        int a=ceil(sqrt(n));
        int cnt=1;
        vector< pair<ll,int> > prime(cnt);

        int idx=0;
        for(int i=2;i<=a;i++){
            if(n==1) break;
            while(1){
                if(n%i==0){
                    //prime[i]++;
                    if(prime[idx].first!=i && prime[idx].first!=0) {idx++; prime.resize(++cnt);}
                    prime[idx].first=i;
                    prime[idx].second++;
                    n/=i;
                }
                else{
                    break;
                }
            }
            if(i%2==1) i++;
        }
        if(n>1){
            if(prime[0].first==0) {prime[0].first=n; prime[0].second=1;}
            else {prime.push_back(make_pair(n,1));}
        }
        ll t1=1; // numerator
        ll t2=1; // denumerator
        while(prime.size()!=0){
            int n=prime.size();
            ll a=prime[n-1].first;
            int cnt=prime[n-1].second;
            prime.pop_back();
            // denumerator
            a%=mod;
            t1*=mul(a,m*cnt+1)-1;
            if (t1==-1) t1+=mod;
            t1%=mod;
            // numerator
            t2*=(a-1);
            t2%=mod;
        }
        t2=mul(t2,mod-2);
        ans=(t1*t2)%mod;
        if(ans<0) {ans+=mod;}
        
        printf("#%d ",test);
        flag?printf("1\n"):printf("%lld\n",ans);
    }
}