#include <cstdio>
using namespace std;
typedef long long ll;

ll n;
bool chk[10];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%lld",&n);

        int cnt=10;
        ll ans=n;

        while(cnt){
            ll tmp=ans;
            while(tmp!=0){
                int ss=tmp%10;
                if(!chk[ss]){
                    chk[ss]=true;
                    --cnt;
                }
                tmp/=10;
                if(cnt==0) break;
            }
            ans+=n;
        }

        printf("#%d %lld\n",tc,ans-n);

        for(int i=0;i<10;++i) chk[i]=false;
    }
    return 0;
}