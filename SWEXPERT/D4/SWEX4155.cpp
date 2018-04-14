#include <cstdio> 
#include <queue>
using namespace std;

const int MAX=1<<6;

int r,c;
char map[51][51];
bool visit[50][50][MAX];
int ans;

const int mov[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

struct Z{
    int x;
    int y;
    int time;
    int state;
};

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=-1;
        queue<Z> que;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;++i){
            scanf("%s",map[i]);
            for(int j=0;j<c;++j){
                for(int k=0;k<MAX;++k) visit[i][j][k]=false;
                if(map[i][j]=='0'){
                    visit[i][j][0]=true;
                    que.push({i,j,0,0});
                }
            }
        }
        bool exit=false;
        while(!que.empty()){
            auto it=que.front();
            que.pop();
            for(int i=0;i<4;++i){
                int di=it.x+mov[i][0];
                int dj=it.y+mov[i][1];
                if(di<0 || di>=r || dj<0 || dj>=c) continue;
                if(visit[di][dj][it.state]) continue;
                if(map[di][dj]=='#') continue;
                
                if(map[di][dj]=='1'){
                    ans=it.time+1;
                    exit=true;
                    break;
                }
                else if('a'<=map[di][dj] && map[di][dj]<='f'){
                    visit[di][dj][it.state]=true;
                    que.push({di,dj,it.time+1,it.state|(1<<(map[di][dj]-'a'))});
                }
                else if('A'<=map[di][dj] && map[di][dj]<='F'){
                    int tar=map[di][dj]-'A';
                    if((it.state&(1<<tar))==(1<<tar)){
                        visit[di][dj][it.state]=true;
                        que.push({di,dj,it.time+1,it.state});
                    }
                }
                else{
                    visit[di][dj][it.state]=true;
                    que.push({di,dj,it.time+1,it.state});
                }
            }
            if(exit) break;
        }

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}