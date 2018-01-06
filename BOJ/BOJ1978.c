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
    int n=0;
    int sum=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&Isprime);
        sum+=Prime();
    }
    printf("%d\n",sum);
}