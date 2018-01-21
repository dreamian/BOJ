#include <bits/stdc++.h>
typedef long long ll;

int n;
int board[100][100];
ll dp[100][100];

// 하 우
int mov[2][2]={{1,0},{0,1}};

int cnt=0;

void DFS(int x,int y){
    if(board[x][y]!=0){
        for(int i=0;i<2;i++){
            if(x+mov[i][0]>=n || y+mov[i][1]>=n) continue;
            dp[x+board[x][y]*mov[i][0]][y+board[x][y]*mov[i][1]]+=dp[x][y];
            DFS(x+board[x][y]*mov[i][0],y+board[x][y]*mov[i][1]);
            cnt++;
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&board[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==0 || (i==n-1 && j==n-1)) continue;
            int right=j+board[i][j];
            int down=i+board[i][j];

            if(down<n) dp[down][j]+=dp[i][j];
            if(right<n) dp[i][right]+=dp[i][j];
        }
    }

    printf("%lld\n",dp[n-1][n-1]);
    return 0;
}