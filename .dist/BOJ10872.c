#include <stdio.h>

void Fac(int n){
    int cnt_2=0;
    int cnt_5=0;
    int a=1;
    for(;n>=1;n--){
        a*=n;
        while(a%2==0){
            cnt_2++; a/=2;
        }
        while(a%5==0){
            cnt_5++; a/=5;
        }
        a=1;
    }
    printf("%d\n",cnt_2>cnt_5?cnt_5:cnt_2);
}

int main(void){
    int n;
    scanf("%d",&n);
    Fac(n);
}