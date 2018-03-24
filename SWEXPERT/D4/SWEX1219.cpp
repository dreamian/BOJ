#include <cstdio> 
#include <queue>
using namespace std;

int n;
int adj[2][99];
bool chk[99];

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc;;){
        for(int i=0;i<2;++i) for(int j=0;j<99;++j) adj[i][j]=-1;
        for(int j=0;j<99;++j) chk[j]=false; 
        queue<int> que;

        scanf("%d %d",&tc,&n);
        printf("#%d ",tc);

        for(int i=0;i<n;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            if(adj[0][a]!=-1) adj[1][a]=b;
            else adj[0][a]=b;
        }
        // base case
        for(int i=0;i<2;++i) if(adj[i][0]!=-1){
            que.push(adj[i][0]);
            chk[adj[i][0]]=true;
        }
        bool find_ans=false;
        while(!que.empty()){
            int tar=que.front();
            que.pop();

            for(int i=0;i<2;++i) if(adj[i][tar]!=-1){
                if(chk[adj[i][tar]]) continue;
                if(adj[i][tar]==99){
                    find_ans=true;
                    break;
                }
                que.push(adj[i][tar]);
                chk[adj[i][tar]]=true;
            }
            if(find_ans) break;
        }
        find_ans ? printf("1\n") : printf("0\n") ;
        if(tc==10) break;
    }
}