#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAX=1e+5;
int n;
ll sum;
int log_depth;
int parent[MAX+1][18];

struct V{
    int depth;
    vector<int> son;
    V () : depth(0), son() {}
};

inline void update_par(){
    // parent 배열 초기화
    parent[1][0]=-1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=17;++j){
            if(parent[i][j]==-1) break;
            parent[i][j]=-1;
        }
    }
    // parent 배열 구성
    for(int j=0;j<=log_depth;++j){
        for(int i=2;i<=n;++i){
            if(parent[i][j]==-1) continue;
            parent[i][j+1]=parent[parent[i][j]][j];
            //printf("%d %d %d\n",i,j+1,parent[i][j+1]);
        }
    }
}

inline void process(vector<V> &vertex){
    queue<int> que;
    // root 삽입
    que.push(1);
    int prev=1;

    auto find_LCS = [&vertex](int ii, int jj){
        int diff=vertex[ii].depth-vertex[jj].depth;
        if(diff<0){
            swap(ii,jj);
            diff*=-1;
        }
        // i의 depth가 더 긴 상태
        for(int i=0;;++i){
            if(diff==0) break;
            if(diff%2!=0) ii=parent[ii][i];
            diff/=2;
        }
        
        // depth가 같은 상태
        if(ii!=jj){
            for(int i=log_depth;i>=0;--i){
                if(parent[ii][i]==-1) continue;
                if(parent[ii][i]!=parent[jj][i]){
                    ii=parent[ii][i];
                    jj=parent[jj][i];
                }
            }
            ii=parent[ii][0];
        }

        return ii;
    };

    while(!que.empty()){
        int out=que.front();
        que.pop();
        // 이전 노드와의 공통 조상을 찾는다
        int anc=find_LCS(prev,out);
        // prev - anc - out의 경로를 누적시킨다
        sum+=vertex[prev].depth+vertex[out].depth-2*vertex[anc].depth;
        // prev 갱신
        prev=out;
        for(const auto& next : vertex[prev].son) que.push(next);
    }
}

int main(){
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        sum=0;
        int max_dep=-1;
        scanf("%d",&n);
        vector<V> vertex(n+1);
        for(int i=2;i<=n;++i){
            int pp;
            scanf("%d",&pp);
            // 부모 노드의 자식 갱신
            vertex[pp].son.emplace_back(i);
            // 현재 노드 정보 갱신
            vertex[i].depth=vertex[pp].depth+1;
            // max depth 갱신
            max_dep=max(max_dep,vertex[i].depth);

            // parent 배열 정보 갱신
            parent[i][0]=pp;
        }
        log_depth=log2(max_dep);

        update_par();
        process(vertex);

        printf("#%d %lld\n",tc,sum);
    }
    return 0;
}