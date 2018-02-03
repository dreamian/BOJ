#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;
#define INF 1e+9

// n: 지점, m: 도로, w: 웜홀
int v,m,w;
int e;
int dist[501];

bool BellmanFord(vector< tuple<int,int,int> > &edges){
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
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&v,&m,&w);

        // 거리 정보 초기화
        dist[1]=0;
        for(int i=2;i<=v;++i) dist[i]=INF;
        vector< tuple<int, int, int> > edges(0);
        e=2*m+w;
        int from,to,wei;
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&from,&to,&wei);
            edges.emplace_back(make_tuple(from,to,wei));
            edges.emplace_back(make_tuple(to,from,wei));
        }
        for(int i=0;i<w;++i){
            scanf("%d%d%d",&from,&to,&wei);
            edges.emplace_back(make_tuple(from,to,-wei));
        }
        bool ispossible=BellmanFord(edges);
        ispossible?printf("YES\n"):printf("NO\n");
    }
    return 0;
}