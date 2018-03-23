#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int sp;
pii ans;
vector<int> adj[101];
bool chk[101];
queue<pii> que;

inline void init(){
    for(int i=1;i<=100;++i){
        adj[i].clear();
        chk[i]=false;
    }
    ans=mp(-1,-1);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        init();
        int len;
        scanf("%d %d",&len,&sp);
        que.push(mp(0,sp));
        chk[sp]=true;
        len/=2;
        int ff,tt;
        for(int i=0;i<len;++i){
            scanf("%d%d",&ff,&tt);
            adj[ff].emplace_back(tt);
        }
        while(!que.empty()){
            auto it=que.front();
            que.pop();
            int pr=0;
            for(int next : adj[it.second]){
                if(chk[next]) continue;
                que.push(mp(it.first+1,next));
                chk[next]=true;
                ++pr;
            }
            if(!pr){
                if(ans.first<it.first){
                    ans=it;
                }
                else if(ans.first==it.first){
                    if(ans.second<it.second){
                        ans=it;
                    }
                }
            }
        }
        printf("#%d %d\n",tc,ans.second);
    }
    return 0;
}