#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int t=1;
    scanf("%d",&t);
    for(int tc=0;tc<t;++tc){
        int n,k;
        scanf("%d%d",&n,&k);
        vector<bool> tap(n+1,false);
        vector<bool> restap(n+1,false);
        for(int i=0;i<k;++i){
            int xi;
            scanf("%d",&xi);
            tap[xi]=true;
        }
        int minTime=1;
        while(1){
            bool alltapped=true;
            for(int i=1;i<=n;++i){
                if(!tap[i]){
                    alltapped=false;
                    break;
                }
            }
            if(alltapped) break;
            ++minTime;
            
            for(int i=1;i<=n;++i){
                if(tap[i] && !tap[i-1]) restap[i-1]=true;
                if(tap[i] && !tap[i+1]) restap[i+1]=true;
            }
            for(int i=1;i<=n;++i){
                if(restap[i]) tap[i]=true;
            }
        }
        printf("%d\n",minTime);
    }
}