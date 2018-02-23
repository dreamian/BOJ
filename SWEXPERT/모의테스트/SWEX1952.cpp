// BFS code

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int min_cost;
int ticket[4];
int info[12];
priority_queue< pii, vector<pii>, greater<pii> > que;

int main(){
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        min_cost=1e+9;
        for(int i=0;i<4;++i) scanf("%d",&ticket[i]);
        for(int i=0;i<12;++i){
            scanf("%d",&info[i]);
        }
        min_cost=min(min_cost,ticket[3]);
        que.push(mp(0,0));
        while(!que.empty()){
            pii v=que.top();
            que.pop();
            
            if(v.second>=12){
                min_cost=min(min_cost,v.first);
                continue;
            }
            if(min_cost<=v.first) continue;

            int add;

            // 1-day
            add=info[v.second]*ticket[0];
            if(v.first+add<min_cost)
            que.push(mp(v.first+add,v.second+1));

            // 1-month
            add=ticket[1];
            if(v.first+add<min_cost)
            que.push(mp(v.first+add,v.second+1));

            // 3-month
            add=ticket[2];
            if(v.first+add<min_cost)
            que.push(mp(v.first+add,v.second+3));
            
        }



        printf("#%d ",tc);
        printf("%d\n",min_cost);
    }
}

/* DFS code

#include <cstdio>
#include <algorithm>
using namespace std;
 
int min_cost;
int ticket[4];
int info[12];
 
inline void DFS(int start, int cost){
    if(start>=12){
        min_cost=min(min_cost,cost);
        return;
    }
    if(cost>=min_cost) return;
 
    int add;
 
    // 1-day
    add=info[start]*ticket[0];
    DFS(start+1,cost+add);
     
 
    // 1-month
    add=ticket[1];
    DFS(start+1,cost+add);
 
    // 3-month
    add=ticket[2];
    DFS(start+3,cost+add);

}
 
int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        for(int i=0;i<4;++i) scanf("%d",&ticket[i]);
        for(int i=0;i<12;++i){
            scanf("%d",&info[i]);
        }
        min_cost=ticket[3];
        DFS(0,0);
 
 
 
        printf("#%d ",tc);
        printf("%d\n",min_cost);
    }
}

*/