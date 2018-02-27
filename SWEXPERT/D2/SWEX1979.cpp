#include <cstdio>
using namespace std;

int r_dp[15][15];
int c_dp[15][15];
int cnt[16];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n,k;
        scanf("%d%d",&n,&k);
        // init
        for(int i=1;i<=n;++i) cnt[i]=0;

        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            int a;
            scanf("%d",&a);
            if(a==1){
                // 가로
                if(i==0) r_dp[i][j]=1;
                else r_dp[i][j]=r_dp[i-1][j]+1; 
                // 세로
                if(j==0) c_dp[i][j]=1;
                else c_dp[i][j]=c_dp[i][j-1]+1;   
            }
            else{
              r_dp[i][j]=0;  
              c_dp[i][j]=0;
              if(i!=0) ++cnt[r_dp[i-1][j]];
              if(j!=0) ++cnt[c_dp[i][j-1]]; 
            }
            if(i==n-1) ++cnt[r_dp[i][j]];
            if(j==n-1) ++cnt[c_dp[i][j]];
        }
        printf("#%d %d\n",tc,cnt[k]);
    }
    return 0;
}