#include <cstdio>
using namespace std;
typedef long long ll;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        ll s1=(ll)n*(n+1)/2;
        ll s2=(ll)n*n;
        ll s3=(ll)n*(n+1);
        printf("#%d %lld %lld %lld\n",tc,s1,s2,s3);
    }
    return 0;
}