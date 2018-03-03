#include <cstdio>
using namespace std;

int min_cost;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int p,q,r,s,w;
        scanf("%d%d%d%d%d",&p,&q,&r,&s,&w);

        // cost A
        int cost_a=p*w;
        // cost B
        int cost_b=q;
        if(w>r) cost_b+=(w-r)*s;

        printf("#%d ",tc);
        cost_a < cost_b ? printf("%d",cost_a) : printf("%d",cost_b);
        printf("\n");
    }
    return 0;
}