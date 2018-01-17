#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define N que.front().first.first
#define M que.front().first.second
#define H que.front().second

int board[101][101][101];
bool chk[101][101][101];
queue< pair<pair<int,int>,int> > que;

// 상 하 좌 우 위 아래
int mov[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,1},{0,0,-1}};
int m,n,h;
void query(int i, int j,int k){
    // 상 하 좌 우 위 아래에 대해 익지 않은 토마토를 익힌다.
    // -1인 경우에는 빈 경우이므로 생략
    for(int idx=0;idx<6;idx++){
        if(i+mov[idx][0]==-1 || i+mov[idx][0]==n || j+mov[idx][1]==-1 || j+mov[idx][1]==m || k+mov[idx][2]==-1 || k+mov[idx][2]==h) continue;
        if(board[i+mov[idx][0]][j+mov[idx][1]][k+mov[idx][2]]>=0 && !chk[i+mov[idx][0]][j+mov[idx][1]][k+mov[idx][2]]){
                
            if(board[i+mov[idx][0]][j+mov[idx][1]][k+mov[idx][2]]==0){
                board[i+mov[idx][0]][j+mov[idx][1]][k+mov[idx][2]]=board[i][j][k]+1;
                que.push(mp(mp(i+mov[idx][0],j+mov[idx][1]),k+mov[idx][2]));
            }
            else{
                board[i+mov[idx][0]][j+mov[idx][1]][k+mov[idx][2]]=min(board[i][j][k]+1,board[i+mov[idx][0]][j+mov[idx][1]][k+mov[idx][2]]);
            }
        }
    }
}

int main(){
    memset(chk,false,sizeof(chk));
    scanf("%d %d %d",&m,&n,&h);
	for(int k=0;k<h;k++){
    	for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
            	int a;
            	scanf("%d",&a);
            	board[i][j][k]=a;
            	if(a==1) que.push(mp(mp(i,j),k));
        	}
    	}
	}
    if(que.empty()) {printf("-1\n"); return 0;}
    else if(que.size()==n*m*h) {printf("0\n"); return 0;}
    else{
        while(!que.empty()){
            int i=N;
            int j=M;
			int k=H;
            chk[i][j][k]=true;
            que.pop();
            query(i,j,k);
        }
        int max_v=-2;
		for(int k=0;k<h;k++){
        	for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
            	if(board[i][j][k]==0) {printf("-1\n"); return 0;}
            	else max_v=max(board[i][j][k],max_v);
        	}
        	}
		}
        printf("%d\n",max_v-1);
    }
}