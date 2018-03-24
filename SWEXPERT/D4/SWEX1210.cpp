#include <cstdio>
#include <utility>  
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second

int map[100][100];
pii X;

inline void LR_search(){
    const int org=X.y;

    // left
    while(1){
        if(X.y-1<0) break;
        if(map[X.x][X.y-1]==0) break;
        --X.y;
    }
    if(org!=X.y) return;
    // right
    while(1){
        if(X.y+1>99) break;
        if(map[X.x][X.y+1]==0) break;
        ++X.y;
    }
}


inline int process(){
    while(1){
        if(X.x==0) break;
        LR_search();
        --X.x;
    }

    return X.y;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc;;){
        scanf("%d",&tc);
        printf("#%d ",tc);
        
        for(int i=0;i<100;++i)for(int j=0;j<100;++j) scanf("%d",&map[i][j]);

        for(int i=0;i<100;++i){
            if(map[99][i]==2){
                X=mp(99,i); break;
            }
        }
        printf("%d\n",process());
        if(tc==10) break;
    }
    return 0;
}