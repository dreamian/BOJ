#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
#define INF 1e+9


int main(){
    int v,e;
    int start;
    scanf("%d%d",&v,&e);
    // start에서 해당 노드까지의 경로 값 저장
    vector<int> path(v+1,INF);

    vector< map<int, int> > edges(v+1);
    map<int, int>::iterator it;

    scanf("%d",&start);
    path[start]=0;
    for(int i=0;i<e;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        it=edges[u].find(v);
        if(it!=edges[u].end()){
            it->second=min(it->second,w);
        }
        else{
            edges[u].insert(make_pair(v,w));
        }
    }
    queue<int> list;
    list.push(start);
    while(!list.empty()){
        int ss=list.front();
        list.pop();
        for(const auto& son : edges[ss]){
            if(path[son.first]<=path[ss]+son.second) continue;
            
            list.push(son.first);
            path[son.first]=min(path[son.first],path[ss]+son.second);
        }
    }
    for(int i=1;i<=v;++i){
        if(path[i]==INF) printf("INF\n");
        else{
            printf("%d\n",path[i]);
        }
    }
}