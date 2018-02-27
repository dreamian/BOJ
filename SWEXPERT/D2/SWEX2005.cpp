#include <cstdio>
using namespace std;

int dp[10][10];

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d\n",tc);
        int n;
        scanf("%d",&n);
        // init
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) dp[i][j]=0;
        for(int i=0;i<n;++i){
            if(i==0){
                dp[i][0]=1;
                printf("1 ");
            }
            else{
                for(int j=0;j<i+1;++j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                    printf("%d ",dp[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}