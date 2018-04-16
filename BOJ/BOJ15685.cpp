#include <cstdio>
#include <utility>
#include <memory.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

struct Z{
    pii s_idx;
    int s_dir;
    int gen;
};

Z dragon[20];

const int mov[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
pii que[20][10201];
int map[101][101];

int n;

void dp(int num){
    // init
    que[num][0]=dragon[num].s_idx;
    pii end_pt=mp(que[num][0].x+mov[dragon[num].s_dir][0],que[num][0].y+mov[dragon[num].s_dir][1]);
    que[num][1]=end_pt;

    int sz=2;
    int cur=2;

    for(int i=0;i<dragon[num].gen;++i){
        int next;
        pii next_end;
        for(int j=0;j<sz;++j){
            if(que[num][j]==end_pt) continue;
            que[num][cur++]=mp(end_pt.x+(end_pt.y-que[num][j].y),end_pt.y-(end_pt.x-que[num][j].x));
            if(j==0) next_end=que[num][cur-1];
        }
        end_pt=next_end;
        sz=cur;
    }

    for(int i=0;i<sz;++i) map[que[num][i].y][que[num][i].x]=1;
}

bool square_test(int i, int j){
    if(map[i][j]==1 && map[i+1][j]==1 && map[i][j+1]==1 && map[i+1][j+1]==1) return true;
    else return false;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&dragon[i].s_idx.x,&dragon[i].s_idx.y,&dragon[i].s_dir,&dragon[i].gen);
        dp(i);
    }
    int ans=0;
    for(int i=0;i<100;++i) for(int j=0;j<100;++j) if(square_test(i,j)) ++ans;
    return ~printf("%d\n",ans);
}