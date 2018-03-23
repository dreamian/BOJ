#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int n,m;

struct BALL{
    int cnt;
    int mem;
    pii red;
    pii blue;
    BALL(): cnt(0), mem(-1) {}
};

struct B{
    char board[10][10];
    queue<BALL> que;
    const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    void get_info(){
        scanf("%d %d\n",&n,&m);
        BALL info;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                char a;
                 scanf("%c",&a);
                 if(a=='R'){
                     info.red=mp(i,j);
                     board[i][j]='.';
                 }
                 else if(a=='B'){
                     info.blue=mp(i,j);
                     board[i][j]='.';
                 }
                 else{
                     board[i][j]=a;
                 }
            }
            getchar();
        }
        que.push(info);
    }
    void process(){
        while(!que.empty()){
            auto it=que.front();
            que.pop();
            
            for(int i=0;i<4;++i){
                BALL next=it;
                if(i==it.mem) continue;
                else if((it.mem!=-1)&&(i==(it.mem+2)%4)) continue;
                int di_r=it.red.first, dj_r=it.red.second;
                int di_b=it.blue.first, dj_b=it.blue.second;
                int di, dj;
                int buf_b=0, buf_r=0;
                bool blue_out=false;

                // blue first
                while(1){
                    di=di_b+mov[i][0];
                    dj=dj_b+mov[i][1];
                    if(board[di][dj]=='#') break;
                    else if(board[di][dj]=='O'){
                        blue_out=true;
                        break;
                    }
                    di_b=di, dj_b=dj;
                    ++buf_b;
                }
                if(blue_out) continue;

                // red second
                while(1){
                    di=di_r+mov[i][0];
                    dj=dj_r+mov[i][1];
                    if(board[di][dj]=='#') break;
                    else if(board[di][dj]=='O'){
                        printf("%d\n",it.cnt+1);
                        return;
                    }
                    di_r=di, dj_r=dj;
                    ++buf_r;
                }
                if(di_r==di_b && dj_r==dj_b){
                    buf_b>buf_r ? (di_b-=mov[i][0], dj_b-=mov[i][1]) : (di_r-=mov[i][0], dj_r-=mov[i][1]);
                }

                if(it.cnt<9&&(buf_r||buf_b)){
                    next.red=mp(di_r,dj_r);
                    next.blue=mp(di_b,dj_b);
                    ++next.cnt;
                    next.mem=i;

                    que.push(next);
                }
            }
        }

        printf("-1\n");
    }
}board;

int main(){
    board.get_info();
    board.process();
}