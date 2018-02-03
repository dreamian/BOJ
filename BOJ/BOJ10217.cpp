#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e+9

int n,max_cost,k;

// 각 공항 지점(101) 해당 비용(10001)을 이용하여 이동했을 때의 누적 시간 저장
int dp[101][10001];

struct E{
    int v, cost, time;
};

struct V{
    int num, cur_cost, cur_time;
    
    bool operator < (const V &i) const{
        if(cur_time==i.cur_time) return cur_cost>i.cur_cost;
        return cur_time>i.cur_time;
    }
};

vector<E> edges[101];
priority_queue<V> que;

inline int dijkstra(){
    
    int min_dist=INF;

    // 시작점 vertex 1
    que.push((V){1,0,0});
    
    // dijkstra
    while(!que.empty()){
        auto cur=que.top();
        que.pop();
        if(cur.num==n){
            min_dist=cur.cur_time;
            break;
        }
        if(dp[cur.num][cur.cur_cost]<cur.cur_time) continue;
        
        int updated_cost, updated_time;
        for(const auto& next : edges[cur.num]){
            updated_cost=cur.cur_cost+next.cost;
            updated_time=cur.cur_time+next.time;
            // ignore
            if(updated_cost>max_cost) continue;
            if(updated_time>=dp[next.v][updated_cost]) continue;

            // updated dp
            dp[next.v][updated_cost]=updated_time;

            // input next node
            que.push((V){next.v,updated_cost,updated_time});
        }
    }

    return min_dist;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){

        scanf("%d%d%d",&n,&max_cost,&k);

        // init
        while(!que.empty()) que.pop();
        for(int i=1;i<=n;++i){
            edges[i].clear();
            for(int j=0;j<=max_cost;++j){
                dp[i][j]=1e+9;
            }
        }

        for(int i=0;i<k;++i){
            int u,v,cc,tt;
            scanf("%d%d%d%d",&u,&v,&cc,&tt);
            edges[u].emplace_back((E){v,cc,tt});
        }

        int ans=dijkstra();

        ans==INF ? printf("Poor KCM\n") : printf("%d\n",ans);
    }
    return 0;
}