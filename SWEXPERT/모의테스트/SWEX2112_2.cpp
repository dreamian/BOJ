#include <cstdio> 
#include <algorithm>
using namespace std;

#define NONE 2
#define A 1
#define B 0

int min_inject;
int d,w,k;
int map[13][20];

int dp[13][20];
vector<int> longest(20);

void DFS(int cur, int cur_type, int prev_type, int cnt){
    // end condition
    if(cnt>=min_inject) return;
    vector<int> tmp=longest;

    // dp와 longest 생성
    if(cur>0){
        for(int i=0;i<w;++i){
            int cur_ = cur_type == NONE ? map[cur][i] : cur_type ;
            int prev_ = prev_type == NONE ? map[cur-1][i] : prev_type ;
            if(cur_ == prev_){
                dp[cur][i]=dp[cur-1][i]+1;
                longest[i]=max(longest[i],dp[cur][i]);
            }
            else dp[cur][i]=1;
        }
    }

    if(cur==d-1){
        bool pass=true;
        for(int i=0;i<w;++i){
            if(longest[i]<k){
                pass=false;
                break;
            }
        }
        if(pass) min_inject=cnt;
        longest=tmp;
        return;
    }

    DFS(cur+1,NONE,cur_type,cnt);
    DFS(cur+1,A,cur_type,cnt+1);
    DFS(cur+1,B,cur_type,cnt+1);
    longest=tmp;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d%d%d",&d,&w,&k);
        min_inject=k;
        for(int i=0;i<d;++i) for(int j=0;j<w;++j) scanf("%d",&map[i][j]);

        // 원래의 맵 정보에 기반해서 dp, longest 초기화
        for(int i=0;i<w;++i){
            dp[0][i]=1;
            longest[i]=1;
        }

        DFS(0,NONE,NONE,0);
        DFS(0,A,NONE,1);
        DFS(0,B,NONE,1);

        printf("#%d %d\n",tc,min_inject);
    }
    return 0;
}