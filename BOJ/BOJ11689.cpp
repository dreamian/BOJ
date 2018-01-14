#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    scanf("%lld",&n);
    ll ans=n;
    if(n==1) {printf("1\n"); return 0;}

    queue<int> que;
    vector<bool> v(ceil(sqrt(n))+1,true);

    que.push(2);
    for(int i=4;i<=v.size();i+=2){
        v[i]=false;
    }

    for(int i=3;i<=v.size();i+=2){
        if(!v[i]) continue;
        que.push(i);
        for(int j=i+i;j<=v.size();j+=i){
            v[i]=false;
        }
    }

    while(!que.empty()){
        int i=que.front();
        if(n%i==0){
            ans/=i;
            ans*=(i-1);
            while(n%i==0){
                n/=i;
            }
        }
        que.pop();
        i=que.front();
    }
    if(n!=1){
        ans/=n;
        ans*=(n-1);
    }
    printf("%lld\n",ans);
    return 0;
}