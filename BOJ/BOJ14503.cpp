#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define x(i) i.first
#define y(i) i.second

int r,c;
int dir;
pii cur;
int map[50][50];

// 12 - 3 - 6 - 9
const int mov[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

inline bool process(int iter){
    int di, dj;
    if(iter==4){
        di=x(cur)+mov[(dir+2)%4][0];
        dj=y(cur)+mov[(dir+2)%4][1];
        
        if(di<0 || di>=r || dj<0 || dj>=c) return false;
        else if(map[di][dj]==1) return false;
        else{
          x(cur)=di;
          y(cur)=dj;
          return process(0);  
        }
    }

    bool res=true;

    dir = (dir+3)%4 ;

    di=x(cur)+mov[dir][0];
    dj=y(cur)+mov[dir][1];
    
    if(di<0 || di>=r || dj<0 || dj>=c) return process(iter+1);
    else if(map[di][dj]==0){
        x(cur)=di;
        y(cur)=dj;
    }
    else return process(iter+1);

    return res;
}

int main(){
    scanf("%d%d",&r,&c);
    scanf("%d%d%d",&x(cur),&y(cur),&dir);

    for(int i=0;i<r;++i) for(int j=0;j<c;++j) scanf("%d",&map[i][j]);

    int cnt=0;
    while(1){
        ++cnt;
        map[x(cur)][y(cur)]=2;
        bool pos=process(0);
        if(!pos) break;
    }
    printf("%d\n",cnt);
}