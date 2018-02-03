// 8ms consumed code
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define vpii vector< pair<int,int> >
#define pii pair< int,int >
#define mp make_pair
#define INF 1e+9
#define adj_node(i) i.first
#define adj_wei(i) i.second

int v,e;
bool chk_inque[501];
int cnt_update[501];
int dist[501];
priority_queue< pii,vector<pii> > que;

inline bool SPFA(vector< vpii > &adj){
    bool hasNC=false;

    // Init
    que.push(mp(cnt_update[1],1));
    chk_inque[1]=true;

    while(!que.empty()){
        int i=que.top().second;
        chk_inque[i]=false;
        que.pop();
        if(++cnt_update[i]>=v) return true;

        for(const auto& next : adj[i]){
            if(dist[adj_node(next)]<=dist[i]+adj_wei(next)) continue;
            // update
            dist[adj_node(next)]=dist[i]+adj_wei(next);

            if(!chk_inque[adj_node(next)]){
                que.push(mp(cnt_update[adj_node(next)],adj_node(next)));
                chk_inque[adj_node(next)]=true;
            }

        }
    }

    return hasNC;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    scanf("%d%d",&v,&e);
    vector< vpii > adj(v+1);
    // Initiation
    dist[1]=0;
    for(int i=2;i<=v;++i) dist[i]=INF;

    for(int i=0;i<e;++i){
        int from,to,wei;
        scanf("%d%d%d",&from,&to,&wei);
        adj[from].emplace_back(mp(to,wei));
    }
    bool hasNC=SPFA(adj);
    //for(int i=1;i<=v;++i) printf("%d**\n",dist[i]);
    if(hasNC){
        printf("-1\n");
    }
    else{
        for(int i=2;i<=v;++i){
            if(dist[i]==INF) printf("-1\n");
            else printf("%d\n",dist[i]);
        }
    }
}