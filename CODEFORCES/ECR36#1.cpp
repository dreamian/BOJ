#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;i--){
        if(k%v[i]==0) {printf("%d\n",k/v[i]); break;}
    }
    return 0;
}