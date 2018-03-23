#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

struct S{
    int n;
    int dir;
    pii head;
    pii tail;
    int map[100][100];
    pii next[100][100];
    int timeline[10001];
    int time;
    const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    S(): head(mp(0,0)), tail(mp(0,0)), time(0), dir(3) {
    }
    void init(){
        scanf("%d\n",&n);
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) map[i][j]=0;
        map[0][0]=2;
        int k;
        scanf("%d\n",&k);
        while(k--){
            int x, y;
            scanf("%d %d\n",&x,&y);
            map[--x][--y]=1;
        }
        int ord;
        scanf("%d\n",&ord);
        int sec;
        char D;
        while(ord--){
            scanf("%d %c",&sec,&D);
            getchar();
            // counter-clockwise
            if(D=='L') timeline[sec]=1;
            // clockwise
            else timeline[sec]=-1;
        }
    }
    bool progress(){
        bool res=false;
        ++time;
        int di=head.x+mov[dir][0];
        int dj=head.y+mov[dir][1];
        if(di<0 || di>n-1 || dj<0 || dj>n-1) return true;

        next[head.x][head.y]=mp(di,dj);
        head=mp(di,dj);

        // self-crash
        if(map[di][dj]==2) return true;
        // eat apple
        else if(map[di][dj]==1){
            map[di][dj]=2;
        }
        else{
            map[tail.x][tail.y]=0;
            tail=next[tail.x][tail.y];
            map[di][dj]=2;
        }

        dir=(dir+timeline[time]+4)%4; 

        return res;
    }
}snake;

int main(){
    snake.init();
    while(!snake.progress());
    printf("%d\n",snake.time);
}