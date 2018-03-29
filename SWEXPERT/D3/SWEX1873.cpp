#include <cstdio>
#include <utility> 
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

char map[21][21];
int ord;
char order[101];
int r,c;
const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
const char exp[4]={'^','<','v','>'};

int dir;
pii tank;

int main(){
    //freopen("sample_input.txt","r",stdin);
    //freopen("output2.txt","w",stdout);
    int t;
    scanf("%d\n",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d %d\n",&r,&c);
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                scanf("%c",&map[i][j]);
                if(map[i][j]=='^') map[i][j]='.', dir=0, tank=mp(i,j);
                else if(map[i][j]=='<') map[i][j]='.', dir=1, tank=mp(i,j);
                else if(map[i][j]=='v') map[i][j]='.', dir=2, tank=mp(i,j);
                else if(map[i][j]=='>') map[i][j]='.', dir=3, tank=mp(i,j);
            }
            scanf("\n");
        }
        scanf("%d",&ord);
        scanf("%s",order);

        for(int i=0;i<ord;++i){
            if(order[i]=='U'){
                dir=0;
                int di=tank.x+mov[dir][0];
                if(di<0) continue;
                else if(map[di][tank.y]=='.') --tank.x;
            }
            else if(order[i]=='L'){
                dir=1;
                int dj=tank.y+mov[dir][1];
                if(dj<0) continue;
                else if(map[tank.x][dj]=='.') --tank.y;
            }
            else if(order[i]=='D'){
                dir=2;
                int di=tank.x+mov[dir][0];
                if(di>=r) continue;
                else if(map[di][tank.y]=='.') ++tank.x;
            }
            else if(order[i]=='R'){
                dir=3;
                int dj=tank.y+mov[dir][1];
                if(dj>=c) continue;
                else if(map[tank.x][dj]=='.') ++tank.y;
            }
            else if(order[i]=='S'){
                int di=tank.x+mov[dir][0], dj=tank.y+mov[dir][1];
                while(1){
                    if(di<0 || di>=r || dj<0 || dj>=c) break;
                    else if(map[di][dj]=='*'){
                        map[di][dj]='.';
                        break;
                    }
                    else if(map[di][dj]=='#'){
                        break;
                    }
                    di+=mov[dir][0], dj+=mov[dir][1];
                }
            }
        }

        map[tank.x][tank.y]=exp[dir];

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                printf("%c",map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}