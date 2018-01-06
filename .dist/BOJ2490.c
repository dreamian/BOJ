#include <stdio.h>

int main(void){
    int a;
    int sum=0;
    int cnt=3;
    while(cnt--){
        for(int i=0;i<4;i++){
            scanf("%d",&a);
            sum+=a;
        }
        if(sum==0) printf("D\n");
        else if(sum==1) printf("C\n");
        else if(sum==2) printf("B\n");
        else if(sum==3) printf("A\n");
        else printf("E\n");
        sum=0;
    }
}