#include <cstdio>
using namespace std;

const int change[8]={50000,10000,5000,1000,500,100,50,10};

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int cost;
        scanf("%d",&cost);
        printf("#%d\n",tc);
        for(int i=0;i<8;++i){
            printf("%d ",cost/change[i]);
            cost%=change[i];
        }
        printf("\n");
    }
    return 0;
}