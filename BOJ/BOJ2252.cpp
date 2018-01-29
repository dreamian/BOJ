#include <cstdio>
#include <vector>
using namespace std;
bool visit[32001];

vector< vector<int> > node(32001,vector<int>(0));

void DFS(int tar){
    if(visit[tar]) return;
    visit[tar]=true;
    int sz=node[tar].size();
    for(int i=0;i<sz;++i){
        DFS(node[tar][i]);
    }
    printf("%d ",tar);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        node[b].push_back(a);
    }
    for(int i=1;i<=n;++i) DFS(i);
    printf("\n");
}