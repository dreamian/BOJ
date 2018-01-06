#include <stdio.h>
#include <string.h>

char a[1001];
char b[1001];
int cache[1001][1001];

int max(int i,int j){
    return i>j?i:j;
}

int LCS(int len_a, int len_b){
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            if(a[i-1]==b[j-1]) cache[i][j]=cache[i-1][j-1]+1;
            else cache[i][j]=max(cache[i-1][j],cache[i][j-1]);
        }
    }
    return cache[len_a][len_b];
}

int main(void){
    scanf("%s%s",a,b);
    memset(cache,0,sizeof(cache));
    int len_a=strlen(a);
    int len_b=strlen(b);
    printf("%d\n",LCS(len_a,len_b));
}