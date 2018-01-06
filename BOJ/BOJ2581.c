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
    int M,N,a;
    int min=0;
    int sum=0;
    scanf("%d %d",&M,&N);
    for(int i=M;i<=N;i++){
        Isprime=i;
        a=Prime();
        if (min==0 && a==1) min=i;
        if (a==1) sum+=i;
    }
    if (sum==0) {printf("%d\n",sum-1);}
    else printf("%d\n%d\n",sum,min);
}