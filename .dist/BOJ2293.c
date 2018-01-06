#include <stdio.h>
#include <malloc.h>

int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    int *coin=(int *)malloc(sizeof(int)*n);
    int *cache=(int *)malloc(sizeof(int)*(k+1));
    cache[0]=1;
    for(int i=0;i<n;i++){
        scanf("%d",&coin[i]);
        for(int j=1;j<k+1;j++){
            if(coin[i]<=j){
                cache[j]+=cache[j-coin[i]];
            }
        }
    }
    printf("%d\n",cache[k]);
    free(coin);
    free(cache);

}