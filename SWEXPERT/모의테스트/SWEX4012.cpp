#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int abs(int i, int j){
    return i-j < 0 ? j-i : i-j;
}

int n, min_v;
int adj[16][16];

inline int get_val(vector<int> &state, int crit){
    int res=0;

    for(int i=0;i<n-1;++i){
        if(state[i]!=crit) continue;
        for(int j=i+1;j<n-1;++j){
            if(state[j]!=crit) continue;
            res+=adj[i][j]+adj[j][i];
        }
    }

    if(crit==1){
        for(int i=0;i<n-1;++i){
            if(state[i]!=crit) continue;
            res+=adj[i][n-1]+adj[n-1][i];
        }
    }

    return res;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        min_v=1e+9;
        scanf("%d",&n);
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) scanf("%d",&adj[i][j]);
        // 마지막은 무조건 1번 팀
        vector<int> state(n-1,0);
        for(int i=n-2;i>n/2-1;--i) state[i]=1;
        do{
            int a=get_val(state,0);
            int b=get_val(state,1);
            min_v=min(min_v,abs(a,b));
        }while(next_permutation(state.begin(),state.end()));
        printf("#%d %d\n",tc,min_v);
    }
    return 0;
}