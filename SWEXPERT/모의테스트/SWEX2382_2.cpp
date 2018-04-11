#include <cstdio> 
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, ans;
const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

struct Z{
    int num, dir, max_v;
    Z () : num(0), dir(-1), max_v(-1) {}
    void init(){
        num=0, max_v=-1;
    }
};

struct Y{
    int x, y, num, dir;
};

Z bio[100][100];
queue<Y> que;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<k;++i){
            Y tmp;
            scanf("%d%d%d%d",&tmp.x,&tmp.y,&tmp.num,&tmp.dir);
            --tmp.dir;
            ans+=tmp.num;
            que.push(tmp);
        }
        for(int i=0;i<m;++i){
            // 미생물 처리 (큐를 비운다)
            while(!que.empty()){
                Y tar=que.front();
                que.pop();
                int di=tar.x+mov[tar.dir][0];
                int dj=tar.y+mov[tar.dir][1];

                if(di==0 || di==n-1 || dj==0 || dj==n-1){
                    int diff=tar.num-tar.num/2;
                    ans-=diff;
                    tar.num/=2;
                    tar.dir = tar.dir%2 == 0 ? ++tar.dir : --tar.dir;
                }
                if(tar.num!=0){
                    bio[di][dj].num+=tar.num;

                    if(bio[di][dj].max_v<tar.num){
                        bio[di][dj].max_v=tar.num;
                        bio[di][dj].dir=tar.dir;
                    }
                }
            }

            // 다음 미생물 준비 (큐를 채운다)
            if(i!=m-1){
                for(int i=0;i<n;++i) for(int j=0;j<n;++j){
                    if(bio[i][j].num==0) continue;
                    que.push({i,j,bio[i][j].num,bio[i][j].dir});
                    bio[i][j].init();
                }
            }
        }

        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            bio[i][j].init();
        }

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}