#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    else return gcd(b,a%b);
}

int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    ll c=gcd(a,b);
    for(int i=0;i<c;i++){
    printf("1");
    }
    printf("\n");
}