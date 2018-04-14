#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
#define x first
#define y second
#define pii pair<int,int>

bool visit[300][300];
int map[300][300];
int n, m;

const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

struct Z{
    pii idx;
    int val;
};

queue<Z> que;

inline void init_visit(){
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) visit[i][j]=false;
}

void ice_test(int i, int j){
    for(int k=0;k<4;++k){
        int di=i+mov[k][0];
        int dj=j+mov[k][1];
        if(di<0 || di>=n || dj<0 || dj>=m) continue;
        if(map[di][dj]==0) continue;
        if(visit[di][dj]) continue;
        visit[di][dj]=true;
        ice_test(di,dj);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int cnt_water=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        scanf("%d",&map[i][j]);
        if(map[i][j]>=1){
            Z tar;
            tar.idx={i,j}, tar.val=map[i][j];
            que.push(tar);
        }
        else ++cnt_water;
    }
    if(!cnt_water){
        printf("0\n");
        return 0;
    }
    int ans=0;
    bool exit_=false;
    while(!que.empty()){
        ++ans;
        // melt
        int sz=que.size();
        for(int i=0;i<sz;++i){
            auto tar=que.front();
            que.pop();
            int sur=0;
            for(int k=0;k<4;++k){
                int di=tar.idx.x+mov[k][0];
                int dj=tar.idx.y+mov[k][1];
                if(di<0 || di>=n || dj<0 || dj>=m) continue;
                if(map[di][dj]!=0) continue;
                ++sur;
            }
            tar.val-=sur;
            tar.val = tar.val < 0 ? 0 : tar.val ;
            que.push(tar);
        }

        // map reconstruct
        for(int i=0;i<sz;++i){
            auto tar=que.front();
            que.pop();
            map[tar.idx.x][tar.idx.y]=tar.val;
            if(tar.val==0) continue;
            que.push(tar);
        }

        // ice_test
        int cnt=0;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j){
            if(map[i][j]==0) continue;
            if(visit[i][j]) continue;
            ice_test(i,j);
            ++cnt;
            if(cnt>1){
                exit_=true; break;
            }
        }
        // init visit arr
        init_visit();

        if(exit_) break;
    }

    que.empty() ? printf("0\n") : printf("%d\n",ans) ;
    return 0;
}