#include <stdio.h>
#include <string.h>

int arr[10001];

int main(void){
    int n,tmp,max=0;
    memset(arr,0,sizeof(int)*10001);
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        arr[tmp]+=1;
        if(max<=tmp) {max=tmp;}        
    }

    for(int i=1;i<=max;i++){
        if (arr[i]!=0) {
         while(arr[i])   {printf("%d\n",i); arr[i]--;}
        }
    }    

}