#include <stdio.h>

int arr[200001];

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int q;
    int l,r;
    unsigned char x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %hhu %hhu",&l,&r,&x,&y);
        for(int s=l;s<=r;s++){
            if(arr[s]==x) arr[s]=y;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}