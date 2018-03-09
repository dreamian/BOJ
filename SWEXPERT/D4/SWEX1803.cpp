#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
typedef long long ll;

const ll INF=1e+12;

int n,m,ss,ee;
ll dist[100001];
bool in_que[100001];
vector<pii> adj[100001];
queue<int> search_que;

inline void init(){
    for(int i=1;i<=n;++i){
        dist[i]=INF;
        adj[i].clear();
        in_que[i]=false;
    }
    dist[ss]=0;
    in_que[ss]=true;
    search_que.push(ss);
}

inline void SPFA(){
    while(!search_que.empty()){
        int v=search_que.front();
        search_que.pop();
        in_que[v]=false;
        for(auto &it : adj[v]){
            if(dist[it.first]>dist[v]+it.second){
                dist[it.first]=dist[v]+it.second;
                if(in_que[it.first]) continue;
                else{
                    in_que[it.first]=true;
                    search_que.push(it.first);
                }
            }
        }
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d%d%d%d",&n,&m,&ss,&ee);
        init();
        for(int i=0;i<m;++i){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            adj[a].emplace_back(mp(b,w));
            adj[b].emplace_back(mp(a,w));
        }
        SPFA();
        printf("#%d %lld\n",tc,dist[ee]);
    }
    return 0;
}