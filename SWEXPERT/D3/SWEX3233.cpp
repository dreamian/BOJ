#include <cstdio> 
using namespace std;
typedef long long ll;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("#%d %lld\n",tc,(ll)(a/b)*(a/b));
    }
    return 0;
}