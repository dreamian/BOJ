#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1>num2){
        return 1;
    }
    else if (num1<num2){
        return -1;
    }

    else return 0;
}

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(void){
    int t;
    scanf("%d",&t);
    int cache[t];
    int new[t-1];
    for(int i=0;i<t;i++){
        scanf("%d",&cache[i]);
    }
    qsort(cache,sizeof(cache)/sizeof(int),sizeof(int),compare);

    for(int i=0;i<t-1;i++){
        new[i]=abs(cache[i+1]-cache[i]);
    }
    int a=new[0];
    for(int i=0;i<t-2;i++){
        a=gcd(a,new[i+1]);
    }
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            printf("%d ",i);
        }
    }
    printf("%d",a);
    printf("\n");

}