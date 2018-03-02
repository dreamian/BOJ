#include <cstdio>
using namespace std;
typedef long long ll;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ll n;
        scanf("%lld",&n);
        while(n>=10){
            int tmp=0;
            while(n!=0){
                tmp+=n%10;
                n/=10;
            }
            n=tmp;
        }
        printf("#%d %lld\n",tc,n);
    }
    return 0;
}