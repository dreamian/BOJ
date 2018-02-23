#include <cstdio>
using namespace std;

int region[20][20];
bool chk[101];
bool chk_s;
int max;

int n;
int dir_;
int si,sj;
int dir[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};

void DFS(int i,int j, int cnt ,int mem){
    // 지역을 벗어나는 경우 처리
    if(i<0 || i>n-1 || j<0 || j>n-1) return;
    
    // 시작점으로 다시 되돌아오는 경우 처리
    if(i==si && j==sj){
        if(chk_s){
            max=max>cnt?max:cnt;
            return;
        }
        else chk_s=true;
    }

    // 같은 숫자가 반복되는 경우 처리
    if(chk[region[i][j]]) return;
    else chk[region[i][j]]=true;

    for(int idx=0;idx<4;++idx){
        int di=i+dir[idx][0], dj=j+dir[idx][1];
        if(mem==0 && idx==0 && di<=n && dj<=n){
            DFS(di,dj,cnt+1,0);
            DFS(di,dj,cnt+1,1);
        }
        if(mem==1 && idx==1 && di<=n && dj>=-1){
            DFS(di,dj,cnt+1,1);
            DFS(di,dj,cnt+1,2);
        }
        if(mem==2 && idx==2 && di>=-1 && dj>=-1){
            DFS(di,dj,cnt+1,2);
            DFS(di,dj,cnt+1,3);
        }
        if(mem==3 && idx==3 && di-si==sj-dj){
            DFS(di,dj,cnt+1,3);
        }
    }
    chk[region[i][j]]=false;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        max=-1;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&region[i][j]);
            }
        }
        for(int i=0;i<n-1;++i){
            for(int j=1;j<n-1;++j){
                dir_=0;
                si=i, sj=j;
                chk_s=false;
                DFS(i,j,0,0);
            }
        }

        printf("#%d %d\n",tc,max);
    }
    return 0;
}