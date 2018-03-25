#include <cstdio> 
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX=1e+5;

int cloth[MAX];

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n; ll sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&cloth[i]);
            sum+=cloth[i];
        }
        sort(cloth,cloth+n,greater<int>());
        for(int i=2;i<n;i+=3) sum-=cloth[i];
        printf("#%d %lld\n",tc,sum);
    }
    return 0; 
}