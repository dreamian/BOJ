#include <stdio.h>
#include <memory.h>

int map[501][501];
int dp[501][501];

int Solve(int i,int j){
    if(i==0 && j==0) return dp[i][j]=1;
    else if(dp[i][j]==-1){
        dp[i][j]=0;
        if(map[i-1][j]>map[i][j]) dp[i][j]+=Solve(i-1,j); 
        if(map[i+1][j]>map[i][j]) dp[i][j]+=Solve(i+1,j);
        if(map[i][j-1]>map[i][j]) dp[i][j]+=Solve(i,j-1);
        if(map[i][j+1]>map[i][j]) dp[i][j]+=Solve(i,j+1);
    }
    
    return dp[i][j]; 
}


int main(void){
    int m,n;
    memset(dp,-1,sizeof(int)*501*501);
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){ // 맵에 값 저장
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }    

    printf("%d\n",Solve(m-1,n-1));
}