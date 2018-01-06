#include <stdio.h>

int max(int i,int j){
    return i>j?i:j;
}

int main(void)
{
	int n;

	freopen("input.txt", "r", stdin);

	scanf("%d", &n);

    int stair[n];
    int dp[n];

	for(int i=0; i<n; i++){	
        scanf("%d",&stair[i]);
        if(i==0) dp[i]=stair[i];
        else if(i==1) dp[i]=dp[0]+stair[i];
        else if(i==2) dp[i]=max(dp[0],stair[1])+stair[i];
        else{
            dp[i]=max(stair[i-1]+dp[i-3],dp[i-2])+stair[i];
        }
	}

    printf("%d\n",dp[n-1]);

	return 0;
}