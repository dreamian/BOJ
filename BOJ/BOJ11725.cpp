#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];

void DFS(vector<int> &par,int cur){
    for(int next: adj[cur]){
        if(par[next] == 0){
        par[next]=cur;
        DFS(par,next);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int> par(n+1);
    // root
    par[1]=-1;
    for(int i=0;i<=n-2;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(par,1);
    for(int i=2;i<=n;i++) printf("%d\n",par[i]);
    
}