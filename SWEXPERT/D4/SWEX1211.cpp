#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

const int INF=1e+9;

int map[100][100];
pii ans;

inline pii LR_search(pii idx){
    const int org=idx.y;

    // left
    while(1){
        if(idx.y-1<0) break;
        if(map[idx.x][idx.y-1]==0) break;
        --idx.y;
    }
    if(org!=idx.y) return idx;
    // right
    while(1){
        if(idx.y+1>99) break;
        if(map[idx.x][idx.y+1]==0) break;
        ++idx.y;
    }
    return idx;
}

inline void process(int X, pii idx, int dist){
    if(dist>ans.first) return;
    if(idx.x==99){
        if(dist==ans.first){
            if(ans.second<X) ans.second=X;
        }
        else ans=mp(dist,X);
    }

    int org_y=idx.y;
    idx=LR_search(idx);
    int diff=idx.y-org_y;
    diff = diff< 0 ? -diff : diff;
    dist+=diff;
    ++idx.x, ++dist;
    process(X,idx,dist);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc;;){
        ans=mp(INF,-1);
        scanf("%d",&tc), printf("#%d ",tc);
        for(int i=0;i<100;++i)for(int j=0;j<100;++j) scanf("%d",&map[i][j]);
        for(int j=0;j<100;++j){
            if(map[0][j]==0) continue;
            process(j,mp(0,j),0);
        }

        printf("%d\n",ans.second);
        if(tc==10) break;
    }
    return 0;
}