#include <cstdio>
#include <set>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
typedef long long ll;

int n;

int main(){
    //freopen("sample_input.txt","r",stdin);
    scanf("%d",&n);
    set< pii > tree;
    set< pii >::iterator high, low;
    // init set
    tree.insert(mp(0,-1));
    tree.insert(mp((int)3e+5+1,-1));
    ll cnt=0;
    for(int i=0;i<n;++i){
        int a;
        scanf("%d",&a);
        high=tree.lower_bound(mp(a,-1));
        low=tree.upper_bound(mp(a,-1));
        --low;
        if(high->second > low->second){
            tree.insert(mp(a,(high->second+1)));
            cnt+=high->second+1;
            printf("%lld\n",cnt);
        }
        else{
            tree.insert(mp(a,(low->second+1)));
            cnt+=low->second+1;
            printf("%lld\n",cnt);
        }
    }
    return 0;
}