#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

int n,m;
int map[20][20];

struct dice{
    pii pos;
    int up;
    int side[4];
    int down;
    dice() : up(0), down(0) {
        for(int i=0;i<4;++i) side[i]=0;
    }
    void update(int i){
        int tmp=up;
        up=side[i];
        side[i]=down;
        down=side[(i+2)%4];
        side[(i+2)%4]=tmp;
        if(map[pos.x][pos.y]==0) map[pos.x][pos.y]=down;
        else{
                down=map[pos.x][pos.y];
                map[pos.x][pos.y]=0;
        }
    }
    void query(int ord){
        if(ord==1){ // east
            if(pos.y==m-1) return;
            ++pos.y;
            update(1); 
        }
        else if(ord==2){ // west
            if(pos.y==0) return;
            --pos.y;
            update(3);
        }
        else if(ord==3){ // north
            if(pos.x==0) return;
            --pos.x;
            update(2);
        }
        else{ // south
            if(pos.x==n-1) return;
            ++pos.x;
            update(0);
        }
        printf("%d\n",up);
    }
}dice;

int main(){
    int ord;
    scanf("%d%d%d%d%d",&n,&m,&dice.pos.first,&dice.pos.second,&ord);

    for(int i=0;i<n;++i) for(int j=0;j<m;++j) scanf("%d",&map[i][j]);

    while(ord--){
        int a;
        scanf("%d",&a);
        dice.query(a);
    }
}