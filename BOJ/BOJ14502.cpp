#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
typedef long long ll;

int max_v;
int n,m;
int map[8][8];
int copyd[8][8];
vector<pii> not_wall;
queue<pii> virus;

const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

inline void query(ll state){
    queue<pii> que=virus;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) copyd[i][j]=map[i][j];

    for(int i=0;i<64;++i){
        if(((1LL<<i)&state) == (1LL<<i)) copyd[not_wall[i].first][not_wall[i].second]=1;
    }

    while(!que.empty()){
        pii tar=que.front();
        que.pop();
        for(int i=0;i<4;++i){
            int di=tar.first+mov[i][0];
            int dj=tar.second+mov[i][1];
            if(di<0 || di>=n || dj<0 || dj>=m) continue;
            if(copyd[di][dj]==0){
                copyd[di][dj]=2;
                que.push(mp(di,dj));
            }
        }
    }

    int area=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        if(copyd[i][j]==0) ++area;
    }

    max_v=max(area,max_v);
}

inline void process(int order, int cnt, ll state){
    if(order>not_wall.size()) return;
    if(cnt==3){
        query(state);
        return;
    }

    process(order+1,cnt,state);

    ++cnt;
    state+=1LL<<order;
    process(order+1,cnt,state);

}

int main(){
    max_v=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        int a;
        scanf("%d",&a);
        map[i][j]=a;
        if(a==0) not_wall.emplace_back(mp(i,j));
        if(a==2) virus.push(mp(i,j));
    }

    process(0,0,0);

    printf("%d\n",max_v);

}