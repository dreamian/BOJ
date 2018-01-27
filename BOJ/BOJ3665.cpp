#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool relation[501][501];
bool visited[501];
bool flag_cyc;

struct T{
    int node;
    int indeg;
}info[501];

void Init_(int n){
    for(int i=1;i<=n;++i){
        info[i].node=-1;
        info[i].indeg=-1;
        visited[i]=false;
        for(int j=1;j<=n;++j) relation[i][j]=false;
    }
    flag_cyc=false;
}

// indeg가 많은 순서대로 정렬 (랭킹 순)
bool cmp_by_rank(const T &i,struct T &j){
    return i.indeg>j.indeg;
}

// node 번호 순으로 정렬
bool cmp_by_node(const T &i,struct T &j){
    return i.node<j.node;
}

void proc_1(int n1, int n2){
    int high=relation[n1][n2]?n1:n2;
    int low=relation[n1][n2]?n2:n1;
    --info[high].indeg;
    ++info[low].indeg;
    relation[low][high]=true;
    relation[high][low]=false;
}

bool proc_dup(){
    int mem=-1;
    for(int i=1;i<=n;++i){
        if(info[i].indeg==mem) return false;
        mem=info[i].indeg;
    }
    return true;
}

void proc_cyc(int i){
    if(visited[i]){
        flag_cyc=true;
        return;
    }
    visited[i]=true;

    for(int j=1;j<=n;++j){
        if(i==j) continue;
        if(relation[i][j]){
            proc_cyc(j);
            if(flag_cyc) return;
            visited[j]=false;
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        Init_(n);
        for(int i=1;i<=n;++i){
            int num;
            scanf("%d",&num);
            info[i].node=num;
            info[i].indeg=n-i;
        }
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                relation[info[i].node][info[j].node]=true;
            }
        }
        sort(info+1,info+n+1,cmp_by_node);
        scanf("%d",&m);
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            // 순위 조정
            proc_1(a,b);
        }

        sort(info+1,info+n+1,cmp_by_rank);

        // 중복 순위 검사
        bool possible=proc_dup();
        if(possible){
            for(int i=1;i<=n;++i){
            printf("%d ",info[i].node);
            }
            printf("\n");
        }
        else{
            // cycle 검사
            for(int i=1;i<=n;++i) {proc_cyc(i); if(flag_cyc) break;}
            bool cycle=flag_cyc;
            cycle?printf("IMPOSSIBLE\n"):printf("?\n");
        }
    }
    return 0;
}