#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int mod=1e+9+7;

char buf[10001];
int dp[10001][16];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    dp[0][1]=1;

    for(int tc=1;tc<=t;++tc){
        scanf("%s",buf);
        int day=strlen(buf);
        for(int i=1;i<=day;++i)for(int j=0;j<16;++j) dp[i][j]=0;
        int key;
        for(int i=1;i<=day;++i){
            if(buf[i-1]=='A') key=1 << 0;
            else if(buf[i-1]=='B') key=1 << 1;
            else if(buf[i-1]=='C') key=1 << 2;
            else key=1 << 3;
            for(int j=0;j<16;++j){
                if(key&j){
                    for(int k=0;k<16;++k){
                        if(j&k) dp[i][j]+=dp[i-1][k];
                        dp[i][j]%=mod;
                    }
                }
            }
        }

        ll ans=0;
        for(int i=0;i<16;++i){
            ans+=dp[day][i];
            ans%=mod;
        }

        printf("#%d %lld\n",tc,ans);
    }
    return 0;
}