#include <stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int Solve(int w,int n,int time[],int dp[],int adj[][1001]){
    if(dp[w]!=0) return dp[w];
    else{
        int result=0;
        for(int i=1;i<=n;i++){
            if(adj[w][i]==1){
                result=max(result,Solve(i,n,time,dp,adj));
            }
        }
        dp[w]=result+time[w];
        return result+time[w];
    }
}


int main(void){
    int t,w;

    scanf("%d",&t);
    while(t--){
        int time[1001]={0,};
        int dp[1001]={0,};
        int adj[1001][1001]={0,};
        int n=0, k=0;

        scanf("%d%d",&n,&k);

        for(int i=1;i<=n;i++){
            scanf("%d",&time[i]);
        }
        while(k--){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[b][a]=1;
        }
        scanf("%d",&w);
        int ans=Solve(w,n,time,dp,adj);
        printf("%d\n",ans);

    }
}