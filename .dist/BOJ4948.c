#include <stdio.h>
#include <math.h>
int Isprime;

int Prime(void){
    int k=sqrt(Isprime);
    int i=2;

    while(i<=k){
        if (Isprime%i==0) {break;}
        i++;
    }
    if (i<=k || Isprime==1) return 0;
    else return 1;
}

int main(void){
    int n;
    int i=0;
    int sum=0;
    while(1){
        scanf("%d",&n);
        if (n==0) return 0;
        
            for(int i=n+1;i<=2*n;i++){
             Isprime=i;
             sum+=Prime();
            }
            printf("%d\n",sum);
            sum=0;
    }
        
}