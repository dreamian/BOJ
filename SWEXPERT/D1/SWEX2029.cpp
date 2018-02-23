#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("#%d %d %d\n",tc,a/b,a%b);
    }
}