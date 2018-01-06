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
    scanf("%d %d",&M,&N);
    for(int i=M;i<=N;i++){
        Isprime=i;
        a=Prime();
        if (a==1) printf("%d\n",i);
    }
}