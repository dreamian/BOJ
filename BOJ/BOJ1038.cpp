#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll dp[11][130];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=10;i++){
        dp[1][i]=i-1;
    }
    int cnt=9;
    if(n<=9) {printf("%d\n",n); return 0;}
    else if(n>1022) {printf("-1\n"); return 0;}
    for(int i=2;cnt<n;i++){
        int k=i-1;
        int idx=1;
        while(k<=9){
            for(int j=1;;j++){
                if(dp[i-1][j]/pow(10,i-2)<k){
                    dp[i][idx++]=k*pow(10,i-1)+dp[i-1][j];
                    cnt++;
                    if(cnt==n) {printf("%lld\n",dp[i][idx-1]); return 0;}
                }
                else break;  
            }
            k++;
        }
    }
    return 0;
}