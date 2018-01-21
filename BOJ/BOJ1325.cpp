#include <bits/stdc++.h>
using namespace std;

int sum;

void DFS(int i,vector< vector<int> > &son,vector<bool> &chk){
    if(chk[i]==true) return;
    chk[i]=true;

    for(int j=0;j<son[i].size();j++){
        if(chk[son[i][j]]==true) continue;
        sum++;
        DFS(son[i][j],son,chk);
    }
}

void Init(vector<bool> &chk){
    int sz=chk.size();
    for(int i=0;i<sz;i++){
        if(chk[i]) chk[i]=false;
    } 
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector < vector<int> > son(n,vector<int>(0));
    vector <int> num(n,0);
    vector <bool> chk(n,false);

    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        son[b-1].push_back(a-1);
    }
    int max_v=-1;
    for(int i=0;i<n;i++){
        sum=0;
        Init(chk);
        DFS(i,son,chk);
        num[i]=sum;
        max_v=max(max_v,sum);
    }
    for(int i=0;i<n;i++){
        if(num[i]==max_v) printf("%d ",i+1);
    }
    printf("\n");
    return 0;
}