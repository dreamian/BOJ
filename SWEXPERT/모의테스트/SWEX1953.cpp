#include <cstdio>
using namespace std;

int ans;
int n,m,r,c,l;
int board[50][50];
bool visit[50][50];
bool check[8][4];

// 상 하 좌 우
int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void Init_check(){
    // type 1
    check[1][0]=true;
    check[1][1]=true;
    check[1][2]=true;
    check[1][3]=true;

    // type 2
    check[2][0]=true;
    check[2][1]=true;

    // type 3
    check[3][2]=true;
    check[3][3]=true;

    // type 4
    check[4][0]=true;
    check[4][3]=true;

    // type 5
    check[5][1]=true;
    check[5][3]=true;

    // type 6
    check[6][1]=true;
    check[6][2]=true;

    // type 7
    check[7][0]=true;
    check[7][2]=true;
}

int iscycle[50][50];

void DFS(int i, int j, int time){
    if(!visit[i][j]) ++ans;
    visit[i][j]=true;
    if(iscycle[i][j]>1) return;
    if(time==l) return;

    int type=board[i][j];

    for(int idx=0;idx<4;++idx){
        int di=i+mov[idx][0];
        int dj=j+mov[idx][1];

        if(di<0 || di>n-1 || dj<0 || dj>m-1) continue;
        
        int target=board[di][dj];
        if(target==0) continue;
        
        int inv_dir;
        if(idx%2==0) inv_dir=idx+1;
        else inv_dir=idx-1; 

        if(!check[type][idx]) continue;
        if(!check[target][inv_dir]) continue;

        ++iscycle[di][dj];
        DFS(di,dj,time+1);
        --iscycle[di][dj];
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    Init_check();
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        scanf("%d %d %d %d %d",&n,&m,&r,&c,&l);
        for(int i=0;i<n;++i)for(int j=0;j<m;++j) {visit[i][j]=false; iscycle[i][j]=0;}
        for(int i=0;i<n;++i)for(int j=0;j<m;++j) scanf("%d",&board[i][j]);

        DFS(r,c,1);

        printf("#%d ",tc);
        printf("%d\n",ans);
    }
    return 0;
}