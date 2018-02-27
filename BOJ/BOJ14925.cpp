#include <cstdio>
using namespace std;

bool board[1000][1000];
int dp[1000][1000];

inline int min(int i, int j, int k){
    i=i<j?i:j;
    i=i<k?i:k;
    return i;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;++i)for(int j=0;j<n;++j){
        int a;
        scanf("%d",&a);
        if(a==1 || a==2) board[i][j]=true;
    }
    int max_v=0;

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(board[i][j]) continue;
            
            if(i==0 || j==0) dp[i][j]=1;
            else dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            
            max_v= max_v > dp[i][j] ? max_v : dp[i][j];
        }
    }
    printf("%d\n",max_v);
}