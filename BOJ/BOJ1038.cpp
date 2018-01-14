#include <bits/stdc++.h>
typedef long long ll;

bool calc(ll i){
    ll copy=i;
    int size=-1;
    while(copy!=0){
        copy/=10;
        size++;
    }
    int a=0;
    int b=0;
    while(size--){
        a=i%10;
        i/=10;
        b=i%10;
        if(b<=a) return false;
    }

    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    if(n<=9) {printf("%d\n",n); return 0;}
    int cnt=9;
    for(ll i=10;cnt<n;i++){
        printf("%lld %d %d**\n",i,cnt,n);
        if(calc(i)) cnt++;
        else continue;
        if(cnt==n) printf("%lld\n",i);
    }
    return 0;
}