#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int,int>

bool visit[1 << 21];
vector< pii > search_que;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        // get input
        int n,m;
        search_que.resize(0);
        scanf("%d%d",&n,&m);
        int tot=(1 << n);
        for(int i=0;i<(1<<n);++i) visit[i]=false;
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);

            int ins=(1<<(a-1))+(1<<(b-1));
            if(visit[ins]) continue;
            else{
                visit[ins]=true;
                pii ele;
                if(a>b) ele.first=b, ele.second=a;
                else ele.first=a, ele.second=b;
                search_que.emplace_back(ele);
                --tot;
            }
        }
        int sz=search_que.size();
        // process
        for(int i=0;i<(1<<n);++i){
            bool flag=false;
            if(visit[i]) continue;
            for(int j=0;j<sz;++j){
                pii couple=search_que[j];
                int state=(1<<(couple.first-1))+(1<<(couple.second-1));
                if((i&state)==state){
                    flag=true;
                    break;
                }
            }
            if(flag) --tot;
        }

        // get output
        printf("#%d %d\n",tc,tot);
    }
    return 0;
}