#include <cstdio> 
#include <queue> 
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int n,m;
queue<pii> que;
bool adj[10][11][11];
int ans;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=-1;
        scanf("%d%d",&n,&m);
        //for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) adj[i][j]=false;

        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[tc-1][a][b]=true, adj[tc-1][b][a]=true;
        }

        for(int i=1;i<=n;++i){
            int node=i;
            int state=1<<i;
            pii it=mp(node,state);
            que.push(it);
        }

        while(!que.empty()){
            pii tar=que.front();
            que.pop();
            int cmp_sz=que.size();
            for(int i=1;i<=n;++i){
                if((tar.second & 1<<i)==1<<i) continue;
                if(!adj[tc-1][tar.first][i]) continue;
                pii next=mp(i,tar.second|(1<<i));
                que.push(next);
            }
            if(cmp_sz==que.size()){
                int cnt=0;
                for(int i=1;i<=n;++i){
                    if((tar.second & 1<<i)==1<<i) ++cnt;
                }
                ans=max(ans,cnt);
                if(ans==n) break;
            }
        }

        while(!que.empty()) que.pop();

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}