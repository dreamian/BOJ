#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define X(i) i.first
#define Y(i) i.second

// 상 하 좌 우
int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool chk[25][25];
char board[25][25];

int n;
int sum;

void DFS(int x,int y){
    for(int i=0;i<4;i++){
        int dx=x+mov[i][0];
        int dy=y+mov[i][1];
        if(dx==-1 || dx==n || dy==-1 || dy==n || chk[dx][dy] || board[dx][dy]=='0') continue;
        chk[dx][dy]=true;
        sum++;
        DFS(dx,dy);
    }
}

int main(void){
    scanf("%d",&n);
    queue<pii> candid;
    for(int i=0;i<n;i++){
        scanf("%s",board[i]);
        for(int j=0;j<n;j++) if(board[i][j]=='1') candid.push(mp(i,j));
    }
    priority_queue < int,vector<int>,greater<int> > ans;
    for(int node=1;!candid.empty();node++){
        pii a;
        X(a)=candid.front().first;
        Y(a)=candid.front().second;
        candid.pop();
        
        if(chk[X(a)][Y(a)]) continue;

        chk[X(a)][Y(a)]=true;
        sum=1;
        DFS(X(a),Y(a));
        ans.push(sum);
    }
    int sz=ans.size();
    printf("%d\n",sz);
    while(!ans.empty()){
        int answer=ans.top();
        printf("%d\n",answer);
        ans.pop();
    }
    return 0;
}