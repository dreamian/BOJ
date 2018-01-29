#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define mp make_pair
#define time(i) info[i].first
#define son(i,j) info[i].second[j] 
using namespace std;


int n;
bool notleaf[501];
int dp[501];

int main(){
    vector< pair<int, vector<int> > > info(501,mp(-1,vector<int>(0)));
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int t;
        scanf("%d",&t);
        time(i)=t;
        while(1){
            int par;
            scanf("%d",&par);
            if(par==-1) break;
            notleaf[i]=true;
            info[par].second.push_back(i);
        }
    }

    queue<int> list;

    for(int i=1;i<=n;++i){
        if(notleaf[i]) continue;
        dp[i]=time(i);
        list.push(i);
    }

    while(!list.empty()){
        int tar=list.front();
        list.pop();

        int sz=info[tar].second.size(); // 자식 노드의 갯수
        for(int cnt=0;cnt<sz;++cnt){
            int next=son(tar,cnt);
            if(dp[next]>=time(next)+dp[tar]) continue;
            dp[next]=time(next)+dp[tar];
            list.push(next);
        }
    }

    for(int i=1;i<=n;++i) printf("%d\n",dp[i]);
    
    return 0;
}