#include <cstdio>
#include <cstring>
using namespace std;

char board[21][21];
short chk[21][21];
int mem;
int dir;
int i,j;
int cnt;

void guide(int r,int c){
    if(dir==1){ // right
        if(j==c-1) j=0;
        else j+=1;
    }
    if(dir==-1){ // left
        if(j==0) j=c-1;
        else j-=1;
    }
    if(dir==2){ // down
        if(i==r-1) i=0;
        else i+=1;
    }
    if(dir==-2){ // up
        if(i==0) i=r-1;
        else i-=1;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++){
        int r=0, c=0;
        memset(chk,0,sizeof(chk));
        mem=0, dir=1; // 1->right -1->left -2->up +2->down

        scanf("%d%d\n",&r,&c);

        for(int a=0;a<r;a++){
            scanf("%s",board[a]);
        }
        i=0, j=0;
        int rn;
        bool ok=true;
        while(ok){
            chk[i][j]+=1;
            if(board[i][j]=='<'){
                dir=-1; if(board[i][j-1]=='>') ok=false;
            } 
            else if(board[i][j]=='>'){
                dir=1; if(board[i][j+1]=='<') ok=false;
            }
            else if(board[i][j]=='^'){
                dir=-2; if(board[i-1][j]=='v') ok=false;
            }
            else if(board[i][j]=='v'){
                dir=2; if(board[i+1][j]=='^') ok=false;
            }
            else if(board[i][j]=='_'){
                if(mem==0) dir=1;
                else dir=-1;
            }
            else if(board[i][j]=='|'){
                if(mem==0) dir=2;
                else dir=-2;
            }
            else if(board[i][j]=='?'){
                rn=rand()%4;
                if(rn==0){
                    dir=-1;
                }
                else if(rn==1){
                    dir=1;
                }
                else if(rn==2){
                    dir=-2;
                }
                else if(rn==3){
                    dir=2;
                }
            }
            else if(board[i][j]=='@'){
                break;
            }
            else if((int)board[i][j]>=(int)'0' && (int)board[i][j]<=(int)'9'){
                mem=board[i][j]-48;
            }
            else if(board[i][j]=='+'){
                if(mem==15) mem=0;
                else mem+=1;
            }
            else if(board[i][j]=='-'){
                if(mem==0) mem=15;
                else mem-=1;
            }
            if(chk[i][j]==1000) ok=false;
            guide(r,c);
            
        }

        printf("#%d ",test);
        ok?printf("YES\n"):printf("NO\n");
    }
}