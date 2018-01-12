#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,r,c;
    scanf("%d%d%d",&n,&r,&c);
    int sum=0;
    n+=1;
    while(n--){
        // 1시
        if(r<(1 << n-1) && (1 << n-1)<=c) {sum+=pow(4,n-1); c-=(1 << n-1);}
        // 7시
        else if((1 << n-1)<=r && c<(1 << n-1)) {sum+=2*pow(4,n-1); r-=(1 << n-1);}
        // 5시
        else if((1 << n-1)<=r && (1 << n-1)<=c) {sum+=3*pow(4,n-1); r-=(1 << n-1); c-=(1 << n-1);}
    }
    printf("%d\n",sum);
}