#include <stdio.h>
#include <malloc.h>
int max(int i,int j,int k){
    if(i>j){
        if(i>k){
            return i;
        }
        else return k;
    }
    else if(j>k){
        return j;
    }
    else return k;
}

int main(void){
    int n;
    scanf("%d",&n);
    int *grape=(int *)malloc(sizeof(int)*(n+1));
    int *dp=(int *)malloc(sizeof(int)*(n+1));
    for(int i=1;i<n+1;i++){
        scanf("%d",&grape[i]);
        if(i==1){
            dp[1]=grape[i];
        }
        else if(i==2){
            dp[2]=grape[i]+dp[1];
        }
        else{
            dp[i]=max(dp[i-1],grape[i]+dp[i-2],grape[i]+grape[i-1]+dp[i-3]);
        }
    }

    printf("%d\n",dp[n]);
    free(grape);
    free(dp);
}