#include <cstdio> 
using namespace std;

int n,m;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d%d",&n,&m);
        printf("%d %d\n",(m<<1)-n,n-m);
    }
    return 0;
}