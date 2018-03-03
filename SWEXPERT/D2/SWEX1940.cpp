#include <cstdio>
using namespace std;

int dis, vel;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        dis=0;
        vel=0;
        int n;
        scanf("%d",&n);
        int order, amount;
        for(int i=0;i<n;++i){
            scanf("%d",&order);
            if(order==0){
                dis+=vel;
            }
            else{
                scanf("%d",&amount);
                order == 1 ? vel+=amount : vel-=amount;
                if(vel<0) vel=0;
                dis+=vel;
            }
        }

        printf("#%d %d\n",tc,dis);
    }
    return 0;
}