#include <bits/stdc++.h>
using namespace std;

int bot[1]={0};
int abov[1]={0};
int side[4]={0,0,0,0};
int x,y;
int n,m;

void query(int ord,vector< vector<int> > &board){
    int temp;
    if(ord==1){ // 동
        if(y+1==m) return;
        y++;
        temp=abov[0];
        abov[0]=side[1];
        side[1]=bot[0];
        bot[0]=side[3];
        side[3]=temp;
    }
    else if(ord==2){ // 서
        if(y-1==-1) return;
        y--;
        temp=abov[0];
        abov[0]=side[3];
        side[3]=bot[0];
        bot[0]=side[1];
        side[1]=temp;
    }
    else if(ord==3){ // 북
        if(x-1==-1) return;
        x--;
        temp=abov[0];
        abov[0]=side[2];
        side[2]=bot[0];
        bot[0]=side[0];
        side[0]=temp;
    }
    else if(ord==4){ // 남
        if(x+1==n) return;
        x++;
        temp=abov[0];
        abov[0]=side[0];
        side[0]=bot[0];
        bot[0]=side[2];
        side[2]=temp;
    }
    printf("%d\n",abov[0]);
    if(board[x][y]==0){
        board[x][y]=bot[0];
    }
    else{
        bot[0]=board[x][y];
        board[x][y]=0;
    }
}

int main(){
    int order;
    scanf("%d%d%d%d%d",&n,&m,&x,&y,&order);
    vector< vector<int> > board(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&board[i][j]);
        }
    }
    for(int i=0;i<order;i++){
        int a;
        scanf("%d",&a);
        query(a,board);
    }
}