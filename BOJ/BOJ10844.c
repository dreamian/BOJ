#include <stdio.h>
typedef long long ll;
ll mod=1000000000;
ll dp[101][10];

int main(){

    int n;
    ll sum=0;
    scanf("%d",&n);
    
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        dp[i][9]=dp[i-1][8];
        for(int j=1;j<9;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
    }

    for(int i=0;i<10;i++){
        sum+=dp[n][i];
        sum%=mod;
    }

    printf("%lld\n",sum);

    return 0;
}