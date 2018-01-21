#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define mp make_pair
#define vpii vector< pair<int,int> >
#define node(a,i) vertex[a][i].first
#define dist(a,i) vertex[a][i].second

int ans=0;
int cmp=0;
int temp;

void DFS(vector< vpii > &vertex,int a,vector<bool> &chk){
    if(ans<cmp){
        ans=cmp;
        temp=a;
    }

    int sz=vertex[a].size();
    for(int i=0;i<sz;i++){
        if(!chk[node(a,i)]){
            chk[node(a,i)]=true;
            cmp+=dist(a,i);
            DFS(vertex,node(a,i),chk);
            cmp-=dist(a,i);
            chk[node(a,i)]=false;
        }
    }
}

int main(){
    int v;
    scanf("%d",&v);
    vector< vpii > vertex(v+1,vpii(0));
    vector<bool> chk(v+1,false);
    queue <int> que;

    for(int i=1;i<=v;i++){
        int v_;
        scanf("%d",&v_);
        while(1){
            int pt;
            scanf("%d",&pt);
            if(pt==-1) break;
            else {
                int dist;
                scanf("%d",&dist);
                vertex[v_].push_back(mp(pt,dist));
            }
        }
        if(vertex[v_].size()==1) que.push(i);
    }
    
    chk[1]=true;
    DFS(vertex,1,chk);
    chk[1]=false;
    chk[temp]=true;
    ans=0; cmp=0;
    DFS(vertex,temp,chk);
    
    printf("%d\n",ans);
}