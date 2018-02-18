#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define mp make_pair
#define pii pair<int, int>
typedef long long ll;


int main(){
    int n;
    scanf("%d",&n);
    vector<int> liquid(n);
    for(int i=0;i<n;++i) scanf("%d",&liquid[i]);
    sort(liquid.begin(),liquid.end());
    int ss=0;
    int ee=n-1;
    ll opti_val=2e+9+1;
    pii ans=mp(-1,-1);
    while(ss<ee){
        int search=liquid[ss]+liquid[ee];
        ll cmp=abs(search);
        if(opti_val>cmp){
            opti_val=cmp;
            ans.first=liquid[ss];
            ans.second=liquid[ee];
        }
        if(search<0) ++ss;
        else --ee;
    }
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}