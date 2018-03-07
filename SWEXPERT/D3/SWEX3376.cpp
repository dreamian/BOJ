#include <cstdio>
using namespace std;

long long dp[101]={0,1,1,1,2,2,};

int main(){
    for(int i=6;+i<=100;++i) dp[i]=dp[i-1]+dp[i-5];
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        printf("#%d %lld\n",tc,dp[n]);
    }
    return 0;
}