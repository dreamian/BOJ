#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int min_3(int i, int j, int k){
    i= i<j ? i:j;
    i= i<k ? i:k;
    return i;
}

int max_3(int i, int j, int k){
    i= i>j ? i:j;
    i= i>k ? i:k;
    return i;
}

const int INT_MAX=100000;
int n;
int board[INT_MAX][3];
int dp[INT_MAX][3];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&board[i][0],&board[i][1],&board[i][2]);
    }
    // base
    dp[0][0]=board[0][0];
    dp[0][1]=board[0][1];
    dp[0][2]=board[0][2];

    // max
    for(int i=1;i<n;++i){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+board[i][0];
        dp[i][1]=max_3(dp[i-1][0],dp[i-1][1],dp[i-1][2])+board[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][2])+board[i][2];
    }
    printf("%d ",max_3(dp[n-1][0],dp[n-1][1],dp[n-1][2]));
    
    // min
    for(int i=1;i<n;++i){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+board[i][0];
        dp[i][1]=min_3(dp[i-1][0],dp[i-1][1],dp[i-1][2])+board[i][1];
        dp[i][2]=min(dp[i-1][1],dp[i-1][2])+board[i][2];
    }
    printf("%d\n",min_3(dp[n-1][0],dp[n-1][1],dp[n-1][2]));
    
    return 0;
}