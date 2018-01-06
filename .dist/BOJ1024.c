#include <stdio.h>
typedef long long ll;

int main(void){
    ll n;
    int l;
    scanf("%lld %d",&n,&l);
    double a;

    for(int len=l;len<=100;len++){
        a=(double)((2.000000*n/len)+1.000000-len)/2.000000;
        int temp=a;
        if((double)temp==a && temp>=0){
            for(int i=0;i<len;i++){
                printf("%d ",temp+i);
            }
            printf("\n");
            break;
        }
        else if(len==100 || temp<0){
            printf("-1\n"); return 0;
        }
    }
}