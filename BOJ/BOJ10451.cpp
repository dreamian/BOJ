#include <bits/stdc++.h>
using namespace std;

int cnt;

void DFS(int i,vector<int> &perm, vector<bool> &visit){
    if(visit[i]) cnt++;
    else{
        visit[i]=true;
        DFS(perm[i],perm,visit);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cnt=0;
        int n;
        scanf("%d",&n);
        vector<int> perm(n+1);
        vector<bool> visit(n+1,false);
        for(int i=1;i<=n;i++) scanf("%d",&perm[i]);
        for(int i=1;i<=n;i++){
            if(!visit[i]) DFS(i,perm,visit);
        }
        printf("%d\n",cnt);
    }
    return 0;
}