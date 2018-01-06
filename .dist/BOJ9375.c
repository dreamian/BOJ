#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef long long ll;

typedef struct Apparel{
    char kind[21];
}AA;

typedef struct Counter{
    int num;
    char kind[21];
}counter;

int main(void){
    
    int t;
    scanf("%d",&t);

    while(t--){

        AA *arr[30];
        counter *num[30];
        
        for(int i=0;i<30;i++){
         arr[i]=(AA *)malloc(sizeof(AA));
         num[i]=(counter *)malloc(sizeof(counter));
        }

        int n;
        scanf("%d",&n);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            scanf("%*s%s",arr[i]->kind);
            if (cnt==0) {strcpy(num[cnt]->kind,arr[i]->kind); num[cnt++]->num+=1;}
            else{
                int temp=cnt;
                for(int j=0;j<temp;j++){
                    if(!strcmp(num[j]->kind,arr[i]->kind)) {num[j]->num+=1; break;}
                    else if(j==cnt-1) {num[cnt]->num=1; strcpy(num[cnt++]->kind,arr[i]->kind);}
                }
            }
        }

        ll ans=1;
        while(cnt--){
            ans*=(1+num[cnt]->num);
        }

        ans-=1;
        printf("%lld\n",ans);
        
    }

    return 0;
    
}
