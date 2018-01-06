#include <stdio.h>
#include <string.h>

char a[1001];
char b[1001];
char ans[1001];
int cache[1001][1001];
int buff=0;

int max(int i,int j){
    return i>j?i:j;
}

int LCS(int len_a, int len_b){
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            if(a[i-1]==b[j-1]){
                cache[i][j]=cache[i-1][j-1]+1;
            }
            else cache[i][j]=max(cache[i-1][j],cache[i][j-1]);
        }
    }
    return cache[len_a][len_b];
}

void String(int len_a, int len_b){
    if(len_a!=-1 && len_b!=-1){
    if(a[len_a-1]==b[len_b-1]){
        ans[buff++]=a[len_a-1];
        String(len_a-1,len_b-1);
    }
    else if(len_a!=0 && len_b!=0){ 
        cache[len_a-1][len_b]>cache[len_a][len_b-1]?String(len_a-1,len_b):String(len_a,len_b-1);
    }
    }
}

int main(void){
    scanf("%s%s",a,b);
    memset(cache,0,sizeof(cache));
    int len_a=strlen(a);
    int len_b=strlen(b);
    printf("%d\n",LCS(len_a,len_b));
    String(len_a,len_b);
    int key=strlen(ans)-1;
    for(int i=key;i>=0;i--){
        printf("%c",ans[i]);
    }
    printf("\n");
}