#include <cstdio>
using namespace std;

int main(){
    int t;
    int ans;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int a=10;
        int b;
        ans=-1;
        while(a--){
            scanf("%d",&b);
            ans= ans > b ? ans : b;
        }

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}