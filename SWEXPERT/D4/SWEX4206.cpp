#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int map[8][8];
bool chk_virus[8][8];
bool chk_man[8][8];
int ans;

const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

struct Z{
    int x;
    int y;
    int time;
};

bool out_of_rangea(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return true;
    else return false;
}

bool zombie_test(){
    bool res=true;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!chk_man[i][j]) continue;
            if(!chk_virus[i][j]){
                return false;
            }
        }
    }
    
    return res;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        queue<Z> virus;
        queue<Z> man;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i) for(int j=0;j<m;++j){
            scanf("%d",&map[i][j]);
            chk_virus[i][j]=false;
            chk_man[i][j]=false;
            if(map[i][j]==2){
                // virus
                virus.push({i,j,0});
            }
            else if(map[i][j]==3){
                // man
                man.push({i,j,0});
                map[i][j]=0;
            }
        }
        ans=0;
        bool exit=false;
        while(1){
            ++ans;
            // virus process
            while(!virus.empty()){
                if(virus.front().time>=ans) break;
                auto it=virus.front();
                virus.pop();
                chk_virus[it.x][it.y]=true;
                for(int i=0;i<4;++i){
                    int di=it.x+mov[i][0];
                    int dj=it.y+mov[i][1];
                    if(out_of_rangea(di,dj)) continue;
                    if(chk_virus[di][dj]) continue;
                    if(map[di][dj]==1) continue;
                    chk_virus[di][dj]=true;
                    map[di][dj]=2;
                    virus.push({di,dj,ans});
                }
            }
            
            // man process
            while(!man.empty()){
                if(man.front().time>=ans) break;
                auto it=man.front();
                man.pop();
                chk_man[it.x][it.y]=true;
                for(int i=0;i<4;++i){
                    int di=it.x+mov[i][0];
                    int dj=it.y+mov[i][1];
                    if(out_of_rangea(di,dj)){
                        exit=true;
                        break;
                    }
                    if(chk_man[di][dj]) continue;
                    if(map[di][dj]==1 || map[di][dj]==2) continue;
                    chk_man[di][dj]=true;
                    man.push({di,dj,ans});
                }
                if(exit) break;
            }
            if(exit) break;
            if(man.empty()&&virus.empty()) break;
        }
        
        if(exit) printf("%d\n",ans);
        else if(zombie_test()) printf("ZOMBIE\n");
        else printf("CANNOT ESCAPE\n");
    }
    return 0;
}
