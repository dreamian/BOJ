#include <cstdio>
#include <algorithm> 
using namespace std;
typedef long long ll;

ll min_v;
int n,a,b;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        min_v=1e+12;
        scanf("%d%d%d",&n,&a,&b);
        for(int r=1;r<=n;++r){
            for(int c=1;r*c<=n;++c){
                if(r<c) continue;
                min_v = min_v < (ll)a*(r-c)+(ll)b*(n-r*c) ? min_v : (ll)a*(r-c)+(ll)b*(n-r*c);
            }
        }
        printf("#%d %lld\n",tc,min_v);
    }
    return 0;
}