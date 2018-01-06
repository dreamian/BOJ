#include <stdio.h>

int dp[100005]={0,};

int main(void){
    int n;
    int idx=1;
    int max=0;
    int min=-1001;
    int vec=-1;
    scanf("%d",&n);
    while(n--){
        int a;
        scanf("%d",&a);
        
        if(a>=0){
            vec++; 
            if(dp[idx]>=0) dp[idx]+=a;
            else dp[++idx]+=a;
        }
        else{
            min=min>a?min:a;
            if(dp[idx]<0) dp[idx]+=a;
            else dp[++idx]+=a;
        }
    }
        if(dp[1]==0 && dp[2]!=0 && dp[3]==0 && vec<0){
            printf("%d\n",min); return 0;
        }

    for(int i=1;;i+=2){
        if (dp[i+2]==0 && dp[i+3]==0){
            max=max>dp[i]?max:dp[i]; break;
        }
        else if (dp[i]+dp[i+1]>0){ 
            dp[i+2]+=dp[i]+dp[i+1];
            max=max>dp[i+2]?max:dp[i+2];
        }
    }

    printf("%d\n",max);
}