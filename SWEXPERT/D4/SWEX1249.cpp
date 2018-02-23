#include <bits/stdc++.h>
#define MAX 100
#define mp make_pair
#define pp pair<int, pair<int,int> >
#define X(pp) pp.second.first
#define Y(pp) pp.second.second
#define sum(pp) pp.first
using namespace std;
int board[MAX][MAX];
// 상 하 좌 우
int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int search(int n){    
    priority_queue< pp,vector<pp>,greater<pp> > min;
    // 초기값에 sum 0, 좌표 0,0 넣기
    min.push(mp(0,mp(0,0)));
    int res=90001;
    vector<vector<int> > cache(n,vector<int>(n,90001));
    while(!min.empty()){
        pp now=min.top();
        min.pop();
        
        if(X(now)==n-1 && Y(now)==n-1) return sum(now);
        else{
            if(cache[X(now)][Y(now)]<=sum(now)) continue;
            cache[X(now)][Y(now)]=sum(now);

            for(int i=0;i<4;i++){
                if(X(now)+mov[i][0]==-1 || X(now)+mov[i][0]==n || Y(now)+mov[i][1]==-1 || Y(now)+mov[i][1]==n) continue;
                min.push(mp(sum(now)+board[X(now)][Y(now)],mp(X(now)+mov[i][0],Y(now)+mov[i][1])));
            }
        }
    }
    return res;
}

int main(){
    freopen("input2.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        memset(board,0,sizeof(board));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char a;
                scanf(" %c",&a);
                board[i][j]=(int)a-(int)'0';
            }
            getchar();
        }
        search(n);
        
        printf("#%d %d\n",tt,search(n));
    }
}