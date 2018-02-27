#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        if(n%2==0) n=-n/2;
        else n=(n+1)/2;
        printf("#%d %d\n",tc,n);
    }
    return 0;
}