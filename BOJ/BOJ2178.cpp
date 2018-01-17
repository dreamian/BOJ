#include <bits/stdc++.h>
using namespace std;
#define foo pair<int,pair<int,int> >
#define mp make_pair
#define sum(i) i.first
#define X(i) i.second.first
#define Y(i) i.second.second

char board[101][101];

// 상 하 좌 우
int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",board[i]);
    }
    priority_queue< foo,vector<foo>,greater<foo> > que;
    que.push(mp(1,mp(0,0)));
    vector< vector<int> > cache(n,vector<int>(m,10001));
    while(!que.empty()){
        foo now=que.top();
        que.pop();

        if(X(now)==n-1 && Y(now)==m-1) {printf("%d\n",sum(now)); return 0;} 
        else{

            if(cache[X(now)][Y(now)]<=sum(now)) continue;
            else cache[X(now)][Y(now)]=sum(now);

            for(int i=0;i<4;i++){
                int dx=X(now)+mov[i][0];
                int dy=Y(now)+mov[i][1];
                if(dx==-1 || dx==n || dy==-1 || dy==m) continue;
                if(board[dx][dy]=='0') continue;
                else que.push(mp(sum(now)+1,mp(dx,dy)));
            }
        }
    }

    return 0;
}