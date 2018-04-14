#include <cstdio> 
#include <utility>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second

int n;
int map[15][15];
bool visit[15][15];
int ans;

const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

struct Z{
    int time;
    pii idx;
    Z() : time(0) {}
};

bool out_of_range(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n) return true;
    else return false;
}

pii end_idx;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=-1;
        queue<Z> que;
        printf("#%d ",tc);
        scanf("%d",&n);
        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            scanf("%d",&map[i][j]);
            visit[i][j]=false;
        }

        // start
        Z tar;
        scanf("%d %d",&tar.idx.x,&tar.idx.y);
        que.push(tar);
        // end
        scanf("%d %d",&end_idx.x,&end_idx.y);

        while(!que.empty()){
            auto it=que.front();
            que.pop();
            if(it.idx.x==end_idx.x && it.idx.y==end_idx.y){
                ans=it.time;
                break;
            }
            visit[it.idx.x][it.idx.y]=true;
            bool only_wait=false;

            for(int i=0;i<4;++i){
                int di=it.idx.x+mov[i][0];
                int dj=it.idx.y+mov[i][1];
                if(out_of_range(di,dj)) continue;
                if(visit[di][dj]) continue;
                if(map[di][dj]==1) continue;
                if(map[di][dj]==2 && (it.time+1)%3!=0){
                    only_wait=true;
                    continue;
                }
                Z next;
                next.time=it.time+1, next.idx={di,dj};
                que.push(next);
            }
            ++it.time;
            if(only_wait) que.push(it);
        }
        printf("%d\n",ans);
    }
    return 0;
}