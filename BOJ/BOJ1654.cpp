#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int k,n;
    ll max_v=-1;
    scanf("%d%d",&k,&n);
    vector<ll> lan(k);

    for(int i=0;i<k;++i){
        scanf("%lld",&lan[i]);
        max_v=max(max_v,lan[i]);
    }
    ll ss=1;
    ll ee=max_v;
    while(ss<=ee){
        ll cnt=0;
        ll mid=(ss+ee)/2;
        for(int i=0;i<k;++i){
            cnt+=lan[i]/mid;
        }
        if(cnt>=(ll)n){
            ss=mid+1;
        }
        else{
            ee=mid-1;
        }
    }
    printf("%lld\n",ss-1);
}