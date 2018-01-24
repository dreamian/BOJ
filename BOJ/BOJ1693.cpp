#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
int dp[100001][18];

void DP(int root, int par){
    dp[root][0]=1e+9;
    for(int i=1;i<18;i++) dp[root][i]+=i;
    for(int it : adj[root]) if(it!=par){
        DP(it,root);
        int min=0, max=0;
        for(int i=1;i<18;i++){
            if(dp[it][max]>dp[it][i]) max=i;
            if(dp[it][min]>dp[it][max]) swap(min,max);
        }
        for(int j=1;j<18;j++) dp[root][j]+=dp[it][min^j? min : max];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // 1을 root로 하는 tree
    DP(1,0);
    printf("%d\n",*min_element(dp[1]+1,dp[1]+18));
}
