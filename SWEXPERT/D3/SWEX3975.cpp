#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);

        if(a*d>b*c) printf("ALICE\n");
        else if(a*d==b*c) printf("DRAW\n");
        else printf("BOB\n");
    }
    return 0;
}