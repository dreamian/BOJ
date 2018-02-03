#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define INF 1e+9
#define mp make_pair

int v;
int dist[3][801];

inline void dijkstra(int i, vector< vector< pii > > &adj, int count){

    // 우선순위 큐에는 dist, node # 순으로 저장한다.
    priority_queue< pii, vector<pii>, greater<pii> > que;
    dist[count][i]=0;
    que.push(mp(dist[count][i],i));
    while(!que.empty()){
        int root=que.top().second;
        que.pop();
        for(const auto& son : adj[root]){
            if(dist[count][son.first]<=dist[count][root]+son.second) continue;
            dist[count][son.first]=dist[count][root]+son.second;
            que.push(mp(dist[count][son.first],son.first));
        }
    }
}

int main(){
    int e;
    scanf("%d%d",&v,&e);
    vector< vector< pii > > adj(v+1);
    for(int i=0;i<3;++i){
        for(int j=1;j<=v;++j){
            dist[i][j]=INF;
        }
    }

    while(e--){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        adj[a].push_back(mp(b,w));
        adj[b].push_back(mp(a,w));
    }

    int key_a,key_b;
    scanf("%d%d",&key_a,&key_b);

    //// from node 1 : Count 0
    dijkstra(1,adj,0);

    // from node 1 to key_a
    int route_1_a=dist[0][key_a];
    
    // from node 1 to key_b
    int route_1_b=dist[0][key_b];

    //// from node a : Count 1
    dijkstra(key_a,adj,1);

    // from node key_a to key_b
    int route_a_b=dist[1][key_b];

    // from node key_a to N
    int route_a_n=dist[1][v];


    if(route_1_a==INF || route_1_b==INF || route_a_b==INF || route_a_n==INF){
        printf("-1\n");
        return 0;
    }

    //// from node b : Count 2
    dijkstra(key_b,adj,2);

    // from key_b to N
    int route_b_n=dist[2][v];

    int tot=min(route_1_a+route_a_b+route_b_n,route_1_b+route_a_b+route_a_n);
    
    printf("%d\n",tot);
    return 0;
}