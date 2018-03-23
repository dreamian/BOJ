#include <cstdio> 
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first 
#define y second 

char map[16][16];
bool chk[16][16];
const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<pii> que;

inline pii find_sp(){
    for(int i=0;i<16;++i){
        for(int j=0;j<16;++j){
            if(map[i][j]=='2') return mp(i,j);
        }
    }
    return mp(-1,-1);
}

inline bool process(){
    pii sp=find_sp();
    que.push(sp);
    chk[sp.x][sp.y]=true;
    while(!que.empty()){
        auto it=que.front();
        que.pop();
        for(int i=0;i<4;++i){
            int di=it.x+mov[i][0];
            int dj=it.y+mov[i][1];
            if(di<0 || di>=16 || dj<0 || dj>=16) continue;
            if(chk[di][dj]) continue;
            if(map[di][dj]=='1') continue;
            if(map[di][dj]=='3') return true;
            que.push(mp(di,dj));
            chk[di][dj]=true;
        }
    }

    return false;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int tc;
    for(;;){
        scanf("%d",&tc);
        printf("#%d ",tc);
        for(int i=0;i<16;++i) scanf("%s",map[i]);
        
        process() ? printf("1\n") : printf("0\n");
        for(int i=0;i<16;++i) for(int j=0;j<16;++j) chk[i][j]=false;
        while(!que.empty()) que.pop();
        if(tc==10) break;
    }
    return 0;
}