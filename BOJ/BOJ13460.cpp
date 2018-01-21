#include <bits/stdc++.h>
using namespace std;

int min_v=11;
int r_x,r_y,b_x,b_y;

void swap(char &a,char &b){
    a^=b;
    b^=a;
    a^=b;
}

void Search(char board[11][11],int cnt){
    if(cnt>=min_v) return;
    char temp[11][11];
    int mem_rx=r_x;
    int mem_ry=r_y;
    int mem_bx=b_x;
    int mem_by=b_y;

    for(int i=0;i<4;i++){
        memcpy(temp,board,sizeof(char)*11*11);
        bool fl_r=false, fl_b=false;
        bool flag=false;
        bool chk=false;
        r_x=mem_rx;
        r_y=mem_ry;
        b_x=mem_bx;
        b_y=mem_by;
        while(!(fl_r&&fl_b)){
            if(i==0){ // 상 
                if(r_x<b_x){ // 빨간 구슬 먼저
                    if(!fl_r){

                    if(temp[r_x-1][r_y]=='.'){
                        swap(temp[r_x-1][r_y],temp[r_x][r_y]);
                        r_x--;
                    }
                    else if(temp[r_x-1][r_y]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;

                    }

                    if(!fl_b){

                    if(temp[b_x-1][b_y]=='.'){
                        swap(temp[b_x-1][b_y],temp[b_x][b_y]);
                        b_x--;
                    }
                    else if(temp[b_x-1][b_y]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    } 
                }
                else{
                    if(!fl_b){

                    if(temp[b_x-1][b_y]=='.'){
                        swap(temp[b_x-1][b_y],temp[b_x][b_y]);
                        b_x--;
                    }
                    else if(temp[b_x-1][b_y]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    }

                    if(!fl_r){

                    if(temp[r_x-1][r_y]=='.'){
                        swap(temp[r_x-1][r_y],temp[r_x][r_y]);
                        r_x--;
                    }
                    else if(temp[r_x-1][r_y]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;

                    } 
                }
            }
            else if(i==1){
                if(r_x>b_x){ // 빨간 구슬 먼저
                    if(!fl_r){

                    if(temp[r_x+1][r_y]=='.'){
                        swap(temp[r_x+1][r_y],temp[r_x][r_y]);
                        r_x++;
                    }
                    else if(temp[r_x+1][r_y]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;

                    }
                    if(!fl_b){

                    if(temp[b_x+1][b_y]=='.'){
                        swap(temp[b_x+1][b_y],temp[b_x][b_y]);
                        b_x++;
                    }
                    else if(temp[b_x+1][b_y]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    } 
                }
                else{
                    if(!fl_b){

                    if(temp[b_x+1][b_y]=='.'){
                        swap(temp[b_x+1][b_y],temp[b_x][b_y]);
                        b_x++;
                    }
                    else if(temp[b_x+1][b_y]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    }
                    if(!fl_r){

                    if(temp[r_x+1][r_y]=='.'){
                        swap(temp[r_x+1][r_y],temp[r_x][r_y]);
                        r_x++;
                    }
                    else if(temp[r_x+1][r_y]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;

                    }
                }
            }
            else if(i==2){
                if(r_y<b_y){ // 빨간 구슬 먼저
                    if(!fl_r){

                    if(temp[r_x][r_y-1]=='.'){
                        swap(temp[r_x][r_y-1],temp[r_x][r_y]);
                        r_y--;
                    }
                    else if(temp[r_x][r_y-1]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;

                    }
                    if(!fl_b){

                    if(temp[b_x][b_y-1]=='.'){
                        swap(temp[b_x][b_y-1],temp[b_x][b_y]);
                        b_y--;
                    }
                    else if(temp[b_x][b_y-1]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    } 
                }
                else{
                    if(!fl_b){

                    if(temp[b_x][b_y-1]=='.'){
                        swap(temp[b_x][b_y-1],temp[b_x][b_y]);
                        b_y--;
                    }
                    else if(temp[b_x][b_y-1]=='O'){
                        fl_b=true;
                        flag=true;
                        chk=true;
                    }
                    else fl_b=true;
                    }
                    if(!fl_r){

                    if(temp[r_x][r_y-1]=='.'){
                        swap(temp[r_x][r_y-1],temp[r_x][r_y]);
                        r_y--;
                    }
                    else if(temp[r_x][r_y-1]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;

                    }
                }
            }
            else{
                if(r_y>b_y){ // 빨간 구슬 먼저
                    if(!fl_r){

                    if(temp[r_x][r_y+1]=='.'){
                        swap(temp[r_x][r_y+1],temp[r_x][r_y]);
                        r_y++;
                    }
                    else if(temp[r_x][r_y+1]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;
                    }
                    if(!fl_b){

                    if(temp[b_x][b_y+1]=='.'){
                        swap(temp[b_x][b_y+1],temp[b_x][b_y]);
                        b_y++;
                    }
                    else if(temp[b_x][b_y+1]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    } 
                }
                else{
                    if(!fl_b){

                    if(temp[b_x][b_y+1]=='.'){
                        swap(temp[b_x][b_y+1],temp[b_x][b_y]);
                        b_y++;
                    }
                    else if(temp[b_x][b_y+1]=='O'){
                        flag=true;
                        fl_b=true;
                        chk=true;
                    }
                    else fl_b=true;
                    }
                    if(!fl_r){

                    if(temp[r_x][r_y+1]=='.'){
                        swap(temp[r_x][r_y+1],temp[r_x][r_y]);
                        r_y++;
                    }
                    else if(temp[r_x][r_y+1]=='O'){
                        //min_v=min(min_v,cnt);
                        flag=true;
                        fl_r=true;
                        temp[r_x][r_y]='.';
                    }
                    else fl_r=true;
                    }
                }
            }
        }
        if(flag && !chk) min_v=min(min_v,cnt);
        if(!flag) Search(temp,cnt+1);
    }
}

int main(){
    int n,m;
    char board[11][11];
    memset(board,'#',sizeof(board));
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c",&board[i][j]);
            if(board[i][j]=='R'){
                r_x=i;
                r_y=j;
            }
            else if(board[i][j]=='B'){
                b_x=i;
                b_y=j;
            }
        }
        getchar();
    }
    Search(board,1);
    min_v>10?printf("-1\n"):printf("%d\n",min_v);
}