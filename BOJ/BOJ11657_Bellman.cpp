// 4ms consumed code
#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;
#define INF 1e+9

// n: 지점, e: 버스
int v,e;
int dist[501];

inline bool BellmanFord(vector< tuple<int,int,int> > &edges){
    bool hasNC=false;

    for(int i=1;i<=v;++i){
        for(const auto& current : edges){
            int from,to,wei;
            tie(from,to,wei)=current;
            if(dist[from]==INF) continue;
            if(dist[from]+wei<dist[to]){
                if(i==v) return true;
                dist[to]=dist[from]+wei;
            }
        }
    }

    return hasNC;
}


int main(){
    //freopen("sample_input.txt","r",stdin);

        scanf("%d%d",&v,&e);

        // 거리 정보 초기화
        dist[1]=0;
        for(int i=2;i<=v;++i) dist[i]=INF;
        vector< tuple<int, int, int> > edges(0);
        
        int from,to,wei;
        for(int i=0;i<e;++i){
            scanf("%d%d%d",&from,&to,&wei);
            edges.emplace_back(make_tuple(from,to,wei));
        }

        bool hasNC=BellmanFord(edges);
        if(hasNC) printf("-1\n");
        else for(int i=2;i<=v;++i){
            if(dist[i]==INF) printf("-1\n");
            else printf("%d\n",dist[i]);
        }

    return 0;
}