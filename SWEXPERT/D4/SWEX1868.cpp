#include <cstdio>
using namespace std;

// 3가지 상태를 나타냄
// 0 : not chekced
// 1 : checked
// -1 : bomb
int map[300][300];
const int mov[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int n;
int ans;

bool is_range(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n) return false;
    else return true;
}

inline bool search(int i, int j){
    bool bomb=false;
    for(int idx=0;idx<8;++idx){
        int di=i+mov[idx][0];
        int dj=j+mov[idx][1];
        if(is_range(di,dj)){
            if(map[di][dj]==-1){
                bomb=true;
                break;
            }
        }
    }
    if(!bomb){
        map[i][j]=1;
        for(int idx=0;idx<8;++idx){
            int di=i+mov[idx][0];
            int dj=j+mov[idx][1];
            if(is_range(di,dj)){
                if(map[di][dj]!=1) search(di,dj);
                map[di][dj]=1;
            }
        }
    }
    return bomb;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d\n",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        scanf("%d\n",&n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                char a;
                scanf("%c",&a);
                if(a=='.') map[i][j]=0;
                else map[i][j]=-1;
            }
            scanf("\n");
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(map[i][j]==-1) continue;
                if(map[i][j]==1) continue;
                ++ans;
                bool bomb=search(i,j);
                if(bomb) --ans;
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(map[i][j]==0) ++ans;
            }
        }
        
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}