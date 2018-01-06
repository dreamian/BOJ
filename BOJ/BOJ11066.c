#include <stdio.h>

int dp[501][501];
int cash[501];
int sum[501]={0,};

int min(int i,int j){
    return i>j?j:i;
}

int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&cash[i]);
            sum[i]=cash[i]+sum[i-1];
        }

        for(int j=1;j<=n;j++){
            for(int i=1;i<n;i++){
                dp[i][i+j]=987654321;
                for(int k=i;k<i+j && i+j<=n;k++){
                    dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+sum[i+j]-sum[i-1]);
                }
            }
        }

        printf("%d\n",dp[1][n]);

    }
}