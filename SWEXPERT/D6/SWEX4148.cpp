#include <cstdio>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pil pair<int,ll>
#define x first
#define y second

int map[30][30];
int dp[30][30][30][30];
int dist[30][30];
ll cnt[30][30];

const int mov[8][2]={
    {-2,1},
    {-1,2},
    {1,2},
    {2,1},
    {-2,-1},
    {-1,-2},
    {1,-2},
    {2,-1}
};

int n,m;

pii ss;
pii ee;

queue<pii> que;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        memset(dp,0,sizeof(dp));
        memset(dist,-1,sizeof(dist));

        scanf("%d%d",&n,&m);

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&map[i][j]);
                if(map[i][j]==3){
                    ss={i,j};
                    map[i][j]=0;
                    dist[ss.x][ss.y]=0;
                    cnt[ss.x][ss.y]=1;
                }
                else if(map[i][j]==4){
                    ee={i,j};
                    map[i][j]=0;
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(map[i][j] == 0) {
                    que.push({i,j});
                    dp[i][j][i][j] = 1;
                    while (!que.empty()){
                        auto tar=que.front();
                        que.pop();
                        for (int k=0;k<8;++k){
                            int di=tar.x+mov[k][0];
                            int dj=tar.y+mov[k][1];
                            if(di<0 || di>=n || dj<0 || dj>=m) continue;
                            if(map[di][dj]!=1) continue;
                            if(dp[i][j][di][dj]!=0) continue;
                            que.push({di,dj});
                            dp[i][j][di][dj]=1;
                        }
                        for(int a=0; a<n;++a){
                            for(int b=0;b<m;++b){
                                if(dp[i][j][a][b]!=1) continue;
                                for (int k=0;k<8;++k){
                                    int di=tar.x+mov[k][0];
                                    int dj=tar.y+mov[k][1];
                                    if(di<0 || di>=n || dj<0 || dj>=m) continue;
                                    if(map[di][dj]!=0) continue;
                                    if(dp[i][j][di][dj]!=0) continue;
                                    dp[i][j][di][dj]=2;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        que.push(ss);
        while(!que.empty()){
            auto tar=que.front();
            que.pop();
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    if(dp[tar.x][tar.y][i][j]==2){
                        if(dist[i][j]==-1){
                            dist[i][j]=dist[tar.x][tar.y]+1;
                            cnt[i][j]=cnt[tar.x][tar.y];
                            que.push({i,j});
                        }
                        else if(dist[i][j]==dist[tar.x][tar.y]+1) cnt[i][j]+=cnt[tar.x][tar.y];
                    }
                }
            }
        }
        
        printf("#%d ",tc);
        if(dist[ee.x][ee.y]==-1) printf("-1\n");
        else printf("%d %lld\n",dist[ee.x][ee.y]-1,cnt[ee.x][ee.y]);
    }
}