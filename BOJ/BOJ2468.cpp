#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int map[100][100];
int max_depth;
bool visit[100][100];

const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

void DFS(int cur_depth, int i, int j){
    if(visit[i][j]) return;

    visit[i][j]=true;
    for(int k=0;k<4;++k){
        int di=i+mov[k][0];
        int dj=j+mov[k][1];
        if(di<0 || di>=n || dj<0 || dj>=n) continue;
        if(map[di][dj]<=cur_depth) continue;
        DFS(cur_depth,di,dj);
    }
}

int main(){
    scanf("%d",&n);
    max_depth=-1;
    for(int i=0;i<n;++i) for(int j=0;j<n;++j){
        scanf("%d",&map[i][j]);
        max_depth=max(max_depth,map[i][j]);
    }

    int ans=1;
    for(int k=1;k<max_depth;++k){
        int cnt=0;
        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            if(map[i][j]<=k) continue;
            if(visit[i][j]) continue;
            DFS(k,i,j);
            ++cnt;
        }
        ans=max(ans,cnt);

        memset(visit,false,sizeof(visit));
    }

    printf("%d\n",ans);
}