#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
typedef long long ll;

int v,e;
bool visit[100001];
ll cnt;
vector<pii> adj[100001];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        priority_queue< pii, vector< pii >, greater< pii > > que;
        scanf("%d%d",&v,&e);
        for(int i=2;i<=v;++i) visit[i]=false;
        for(int i=1;i<=v;++i) adj[i].clear();
        for(int i=0;i<e;++i){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            adj[a].push_back(mp(w,b));
            adj[b].push_back(mp(w,a));
        }
        // base case
        int sz=adj[1].size();
        visit[1]=true;
        for(int i=0;i<sz;++i){
            if(visit[adj[1][i].second]) continue;
            que.push(mp(adj[1][i].first,adj[1][i].second));
        }
        cnt=0;
        int process_cnt=0;
        while(!que.empty()){
            auto it=que.top();
            que.pop();
            if(visit[it.second]) continue;
            ++process_cnt;
            visit[it.second]=true;
            cnt+=it.first;
            if(process_cnt==v-1) break;
            int sz=adj[it.second].size();
            for(int i=0;i<sz;++i){
                if(visit[adj[it.second][i].second]) continue;
                que.push(mp(adj[it.second][i].first,adj[it.second][i].second));
            }
        }
        printf("#%d %lld\n",tc,cnt);
    }
    return 0;
}