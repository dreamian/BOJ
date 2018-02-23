#include <cstdio>
using namespace std;

bool map[50][50];
bool chk[50][50];
int cnt;
int r,c;

// 상, 하, 좌, 우
const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

inline void process(int i, int j){
    chk[i][j]=true;
    for(int dir=0;dir<4;++dir){
        int di=i+mov[dir][0];
        int dj=j+mov[dir][1];
        if(di < 0 ||di >= r || dj < 0 || dj>= c) continue;
        if(chk[di][dj]) continue;

        if(map[di][dj]) process(di,dj);
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d%d%d",&c,&r,&k);
        // Init
        for(int i=0;i<r;++i)for(int j=0;j<c;++j) map[i][j]=false,chk[i][j]=false;

        while(k--){
            int i,j;
            scanf("%d%d",&j,&i);
            map[i][j]=true;
        }
        cnt=0;
        for(int i=0;i<r;++i)for(int j=0;j<c;++j){
            if(!map[i][j]) continue;
            if(chk[i][j]) continue;
            process(i,j);
            ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}