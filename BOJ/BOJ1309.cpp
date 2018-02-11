#include <cstdio>
using namespace std;

int dp[100001];

int main(){
    int n;
    scanf("%d",&n);
    dp[0]=1;
    dp[1]=3;
    for(int i=2;i<=n;++i){
        dp[i]=2*dp[i-1]+dp[i-2];
        dp[i]%=9901;
    }
    printf("%d\n",dp[n]);
}