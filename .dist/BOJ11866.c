#include <stdio.h>

int main(void){
    int m,n;
    int j;
    int a[1001];
    scanf("%d %d",&n,&m);
    j=n;
    printf("<");
    for(int i=0;i<n;i++) {a[i]=i+1;}
    int i=-1;j+=1; while(--j){
        i=(i+m)%j;
        if (j==1) {printf("%d",a[i]);}
        else  {printf("%d, ",a[i]);}
        for(int k=i+1;k<=j;k++){
            a[k-1]=a[k];
        }
        i--;
    }
    printf(">\n");
}