#include <stdio.h>
#include <math.h>

int dp[1000001];

int min(int a,int b,int c){
    if(a<b){
        if(a<c){
            return a;
        }
        else return c;
    }
    else if(b<c){
        return b;
    }
    else return c;
}

int main(void){
    int n;
    scanf("%d",&n);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        if(i%3==0 && i%2==0){
            dp[i]=min(dp[i/3],dp[i/2],dp[i-1])+1;
        }
        else if(i%3==0){
            dp[i]=(dp[i/3]>dp[i-1]?dp[i-1]:dp[i/3])+1;
        }
        else if(i%2==0){
            dp[i]=(dp[i/2]>dp[i-1]?dp[i-1]:dp[i/2])+1;
        }
        else dp[i]=dp[i-1]+1;
    }
    printf("%d\n",dp[n]);
}