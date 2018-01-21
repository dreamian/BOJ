#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#define vpii vector<pair<int,int> >
#define mp make_pair
#define num(i,j) connected[i][j].first
#define weight(i,j) connected[i][j].second
using namespace std;

int ans=0;
bool chk[10001];
int candidate=0;

void DFS(int start, vector < vpii > &connected, int weighted){
    int sz=connected[start].size();
    chk[start]=true;

    for(int i=0;i<sz;i++){
        if(chk[num(start,i)]) continue;
        int next=num(start,i);
        weighted+=weight(start,i);

        DFS(next,connected,weighted);
        weighted-=weight(start,i);
    }
    //ans=ans>weighted?ans:weighted;
    if(weighted>ans){
        ans=weighted;
        candidate=start;
    }
    chk[start]=false;
}


int main(){
    // 간선 갯수
    int n;
    scanf("%d",&n);
    vector< vpii > connected(n+1,vpii(0));
    while(--n){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        connected[a].push_back(mp(b,c));
        connected[b].push_back(mp(a,c));
    }
    queue<int> spare;
    // end-to-end node 저장
    int cnt=connected.size()-1;
    for(int i=1;i<=cnt;i++) if(connected[i].size()==1) spare.push(i);

    /*
    while(!spare.empty()){
        int node=spare.front();
        spare.pop();
        DFS(node,connected,0);
    }
    */
    DFS(1,connected,0);
    DFS(candidate,connected,0);

    printf("%d\n",ans);
    return 0;
}