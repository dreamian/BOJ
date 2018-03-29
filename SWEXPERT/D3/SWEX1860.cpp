#include <cstdio> 
#include <algorithm>
using namespace std;

int costomer[11112];
int n,m,k;
int max_time;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        max_time=-1;
        for(int i=0;i<=11111;++i) costomer[i]=0;
        scanf("%d%d%d",&n,&m,&k);
        while(n--){
            int a;
            scanf("%d",&a);
            ++costomer[a];
            max_time=max(max_time,a);
        }
        bool pos=true;
        int cost=0;
    
        for(int i=0;i<=max_time;++i){
            if(costomer[i]==0) continue;
            cost+=costomer[i];
            if((i/m)*k<cost){
                pos=false;
                break;
            }
        }

        pos ? printf("Possible\n") : printf("Impossible\n");
    }
    return 0;
}