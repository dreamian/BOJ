#include <cstdio>
#include <tuple>
using namespace std;
typedef long long ll;
#define till tuple<int,ll,ll>
#define mt make_tuple

int main(){
    ll n;
    int k;
    scanf("%lld%d",&n,&k);
    // first : bag #, second : residue, third : # of bag
    till ans=mt(0,n+1,-1);
    for(int i=1;i<=k;++i){
        ll cap;
        ll res;
        scanf("%lld",&cap);
        res=n%cap;

        ll cmp_res;
        tie(ignore,cmp_res,ignore)=ans;

        if(cmp_res<res) continue;

        ans=mt(i,res,n/cap);
    }

    int first;
    ll second;
    tie(first,ignore,second)=ans;
    printf("%d %lld\n",first,second);
    return 0;
}