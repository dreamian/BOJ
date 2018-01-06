#include <stdio.h>
typedef long long ll;
ll dp[1001][1001]={0};

ll binomial(ll n,ll k){
    ll val;
    if(k==0 || k==n) {val=1; dp[n][k]=1;}
    else if (k==1||k==(n-1)) {val=n; dp[n][k]=n;}
    else {
        if(dp[n][k]==0){
            dp[n][k]=binomial(n-1,k-1)+binomial(n-1,k);
            val=dp[n][k];
        }
        else val=dp[n][k];
    } 
    return val%1000000007;
}


int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%lld\n",binomial(n,k));
}