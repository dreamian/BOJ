//
//  SW#1949.cpp
//  C_project
//
//  Created by 이승현 on 2018. 1. 20..
//  Copyright © 2018년 이승현. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

int board[21][21];
bool visit[21][21];
int longest;
int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,k;
int max(int i, int j){
    return i>j?i:j;
}

void DFS(int i, int j, int len,bool chk){
    longest=max(longest,len);
    visit[i][j]=true;
    for(int dir=0;dir<4;dir++){
        int dx=i+mov[dir][0];
        int dy=j+mov[dir][1];
        if(dx==-1 || dx==n || dy==-1 || dy==n){
            continue;
        }
        else if(visit[dx][dy]) continue;
        else{
            if(board[dx][dy]<board[i][j]) DFS(dx,dy,len+1,chk);
            else if(!chk){
                if(k>=board[dx][dy]-board[i][j]+1){
                    int temp=board[dx][dy];
                    board[dx][dy]=board[i][j]-1;
                    chk=true;
                    DFS(dx,dy,len+1,chk);
                    board[dx][dy]=temp;
                    chk=false;
                }
            }
        }
        
    }
    visit[i][j]=false;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        memset(visit,false,sizeof(visit));
        longest=0;
        scanf("%d%d",&n,&k);
        int highest=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&board[i][j]);
                highest=highest>board[i][j]?highest:board[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]<highest) continue;
                DFS(i,j,1,false);
            }
        }
        
        
        
        
        
        
        printf("#%d ",tc);
        printf("%d\n",longest);
    }
    return 0;
}
