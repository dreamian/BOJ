#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cnt;
int board[5][5]={0,};
bool ext[10000000]={0,};

void Search(int i,int j, int turn, int mask){
    if(turn==7 && !ext[mask]){
        ext[mask]=1;
        cnt++;
    }
    else if(turn<7){
        if(i!=1) Search(i-1,j,turn+1,mask*10+board[i-1][j]);
        if(i!=4) Search(i+1,j,turn+1,mask*10+board[i+1][j]);
        if(j!=1) Search(i,j-1,turn+1,mask*10+board[i][j-1]);
        if(j!=4) Search(i,j+1,turn+1,mask*10+board[i][j+1]);
    } 
}

int main(){
    int t;
    cin >> t;
    for(int test=1;test<=t;test++){
        cnt=0;
        memset(ext,0,sizeof(ext));
        for(int i=1;i<=4;i++){
            cin >> board[i][1] >> board[i][2] >> board[i][3] >> board[i][4];
        }

        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                Search(i,j,1,board[i][j]);
            }
        }


        printf("#%d %d\n",test,cnt);

    }
}