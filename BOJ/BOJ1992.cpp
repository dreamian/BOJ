#include <cstdio>
using namespace std;

bool board[64][64]={0,};
char str[65];

void Search(int n, int x, int y){
    bool mem=board[x][y];
    bool flag=true;
    for(int i=x;i<n+x && flag;i++){
        for(int j=y;j<n+y && flag;j++){
            if(board[i][j]!=mem){
                printf("(");
                Search(n/2,x,y);
                Search(n/2,x,y+n/2);
                Search(n/2,x+n/2,y);
                Search(n/2,x+n/2,y+n/2);
                flag=false;
            }    
        }
    }
    if(flag) printf("%d",mem);
    else printf(")");
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<n;j++){
            int a=str[j]-(int)'0';
            if(a==1) board[i][j]=1;
            if(a==0) board[i][j]=0;
        }
    }
    Search(n,0,0);
    printf("\n");
}