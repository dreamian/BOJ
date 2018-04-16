#include <cstdio> 
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair

int n,m;
int min_tot;

pii man[100];
pii build[13];

int sz_man;
int sz_build;

inline int abs(int i, int j){
    return i<j ? j-i : i-j ;
}

void DFS(vector<int> &picked){

    int sum=0;

    for(int i=0;i<sz_man;++i){
        int min_v=1e+9;
        for(int j=0;j<sz_build;++j){
            if(picked[j]==0) continue;
            int di=abs(man[i].x,build[j].x);
            int dj=abs(man[i].y,build[j].y);
            min_v=min(min_v,di+dj);
        }
        sum+=min_v;
    }
    min_tot=min(min_tot,sum);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        min_tot=1e+9;
        scanf("%d%d",&n,&m);
        
        sz_man=0;
        sz_build=0;    

        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            int tmp;
            scanf("%d",&tmp);
            if(tmp==1) man[sz_man++]=mp(i,j);
            else if(tmp==2) build[sz_build++]=mp(i,j);
        }

        vector<int> perm(sz_build);
        for(int i=sz_build-1, cur=m;cur>0;--i,--cur) perm[i]=1;

        do{
            DFS(perm);
        }while(next_permutation(perm.begin(),perm.end()));

        printf("#%d %d\n",tc,min_tot);
    }
    return 0;
}