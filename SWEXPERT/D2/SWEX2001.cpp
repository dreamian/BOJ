#include <cstdio>
using namespace std;
#define dbg1 printf("**dbg1\n")
#define dbg2 printf("**dbg2\n")

int dp[15][15];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n,m;
        scanf("%d%d",&n,&m);
        int max_v=0;
        // Init
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) dp[i][j]=0;
        // 아래 방향과 오른쪽 방향으로 dp 누적
        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            int a;
            scanf("%d",&a);
            for(int k=i;k<i+m;++k)for(int l=j;l<j+m;++l){
                if(k>=n || l>=n) continue;
                dp[k][l]+=a;
            }
            if(i>=m-1 && j>=m-1) max_v= max_v > dp[i][j] ? max_v : dp[i][j];
        }
        printf("#%d %d\n",tc,max_v);
    }
    return 0;
}