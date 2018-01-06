#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

void Estim(int target){
    int idx_1=0, idx_2=0, diff=target;
    int a[2];
    for(int i=2;i<=target/2;i++){
        Isprime=i; idx_1=Prime();
        Isprime=target-i; idx_2=Prime();
        if (idx_1==1 && idx_2==1 && diff>abs(target-2*i)) {a[0]=i; a[1]=target-i; diff=abs(target-2*i);}
        if (diff==0) {break;}
    }
    printf("%d %d\n",a[0],a[1]);
}

int main(void){
    int n;
    int a;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
       scanf("%d",&a);
       Estim(a);
    }
        
}