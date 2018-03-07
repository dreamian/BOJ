#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int n;
int map[1000][1000];
bool chk[1000001];
const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

inline int search_up(int i, int j){
    int res=map[i][j];
    for(int idx=0;idx<4;++idx){
        int di=i+mov[idx][0];
        int dj=j+mov[idx][1];
        if(di<0 || di>=n || dj<0 || dj>=n) continue;
        if(map[di][dj]==map[i][j]+1) return search_up(di,dj);
    }

    return res;
}

inline int search_down(int i, int j){
    int res=map[i][j];
    for(int idx=0;idx<4;++idx){
        int di=i+mov[idx][0];
        int dj=j+mov[idx][1];
        if(di<0 || di>=n || dj<0 || dj>=n) continue;
        if(map[di][dj]==map[i][j]-1) return search_up(di,dj);
    }

    return res;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        pii ans=mp(-1,-1);
        scanf("%d",&n);
        int upto=n*n;
        for(int i=1;i<=upto;++i) chk[i]=false;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) scanf("%d",&map[i][j]);

        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            if(chk[map[i][j]]) continue;
            int up=search_up(i,j);
            int down=search_down(i,j);
            int len=up-down+1;
            for(int idx=down;idx<=up;++idx) chk[idx]=true;
            if(ans.first<len){
                ans.first=len;
                ans.second=down;
            }
            else if(ans.first==len && ans.second>down){
                ans.second=down;
            }
        }

        printf("#%d %d %d\n",tc,ans.second,ans.first);
    }
    return 0;
}