#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int board[1001][1001];
bool chk[1001][1001];
queue< pair<int,int> > que;

// 상 하 좌 우
int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int m,n;
void query(int i, int j){
    // 상 하 좌 우에 대해 익지 않은 토마토를 익힌다.
    // -1인 경우에는 빈 경우이므로 생략
    for(int idx=0;idx<4;idx++){
        if(i+mov[idx][0]==-1 || i+mov[idx][0]==n || j+mov[idx][1]==-1 || j+mov[idx][1]==m) continue;
        if(board[i+mov[idx][0]][j+mov[idx][1]]>=0 && !chk[i+mov[idx][0]][j+mov[idx][1]]){
                
            if(board[i+mov[idx][0]][j+mov[idx][1]]==0){
                board[i+mov[idx][0]][j+mov[idx][1]]=board[i][j]+1;
                que.push(mp(i+mov[idx][0],j+mov[idx][1]));
            }
            else{
                board[i+mov[idx][0]][j+mov[idx][1]]=min(board[i][j]+1,board[i+mov[idx][0]][j+mov[idx][1]]);
            }
        }
    }
}

int main(){
    memset(chk,false,sizeof(chk));
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            scanf("%d",&a);
            board[i][j]=a;
            if(a==1) que.push(mp(i,j));
        }
    }
    if(que.empty()) {printf("-1\n"); return 0;}
    else if(que.size()==n*m) {printf("0\n"); return 0;}
    else{
        while(!que.empty()){
            int i=que.front().first;
            int j=que.front().second;
            chk[i][j]=true;
            que.pop();
            query(i,j);
        }
        int max_v=-2;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0) {printf("-1\n"); return 0;}
            else max_v=max(board[i][j],max_v);
        }
        }
        printf("%d\n",max_v-1);
    }
}