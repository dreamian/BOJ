#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;
ll min(ll i, ll j){
    return i=i<j?i:j;
}

int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    vector<int> c(n);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&c[i]); // 가격 정보 저장
    }
    for(int i=0;i<n-1;i++){
        if(c[i]*2<=c[i+1]){
             c[i+1]=2*c[i]; 
        }
    }
    ll ans=9e+18;
    ll sum=0;

    for(int i=n-1;i>=0;i--){
        int need=l/(1 << i);
        sum+=(ll)c[i]*need;
        l-=(need << i);
        ans=min(ans,sum+(l>0)*c[i]);
        if(l==0) break;
    }

    printf("%lld\n",ans);
}