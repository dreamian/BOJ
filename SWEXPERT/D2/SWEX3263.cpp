#include <cstdio>
using namespace std;

int dp[100000];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i) dp[i]=0;
        int max=0;
        for(int i=0;i<n;++i){
            int a;
            scanf("%d",&a);
            dp[a]=dp[a-1]+1;
            max = max > dp[a] ? max : dp[a];
        }    

        printf("#%d %d\n",tc,n-max);
    }
}