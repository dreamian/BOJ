#include <cstdio>
using namespace std;
typedef long long ll;

int price[1000000];

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        ll sum=0;
        for(int i=0;i<n;++i) scanf("%d",&price[i]);
        int max_v=-1;
        for(int i=n-1;i>=0;--i){
            if(price[i]>max_v) max_v=price[i];
            else{
                sum+=max_v-price[i];
            }
        }
        printf("#%d %lld\n",tc,sum);
    }
    return 0;
}