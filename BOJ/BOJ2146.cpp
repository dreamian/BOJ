#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second

int n;

struct Y{
    int val;
    int len;
    Y() : len(0) {}    
}map[100][100];

bool visit[100][100];

const int mov[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

queue<pii> que[5001];
bool inque[5001][100][100];

void dfs(int i, int j, int lab){
    for(int k=0;k<4;++k){
        int di=i+mov[k][0];
        int dj=j+mov[k][1];
        if(di<0 || di>=n || dj<0 || dj>=n) continue;
        if(visit[di][dj]) continue;
        if(map[di][dj].val==0){
            if(inque[lab][i][j]) continue;
            pii tar;
            tar={i,j};
            que[lab].push(tar);
            inque[lab][i][j]=true;
            continue;
        }
        visit[di][dj]=true;
        map[di][dj].val=lab;
        dfs(di,dj,lab);
    }
}

void print_map(){
    printf("\n##dbg\n");
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            printf("%d ",map[i][j].val);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&map[i][j].val);

    // island labeling
    int lab=1;
    for(int i=0;i<n;++i) for(int j=0;j<n;++j){
        if(visit[i][j]) continue;
        if(map[i][j].val==0) continue;
        map[i][j].val=lab;
        dfs(i,j,lab);
        ++lab;
    }
    
    //print_map();

    // out condition
    if(lab<=2){
        printf("0\n");
        return 0;
    }
    int min_v=1e+9;
    bool get_ans=false;
    while(1){
        for(int i=1;i<lab;++i){
            int sz=que[i].size();
            for(int j=0;j<sz;++j){
                auto tar=que[i].front();
                que[i].pop();
                inque[i][tar.x][tar.y]=false;

                for(int k=0;k<4;++k){
                    int di=tar.x+mov[k][0];
                    int dj=tar.y+mov[k][1];
                    if(di<0 || di>=n || dj<0 || dj>=n) continue;
                    if(map[di][dj].val==map[tar.x][tar.y].val) continue;

                    if(map[di][dj].val==0){
                        map[di][dj].val=i;
                        map[di][dj].len=map[tar.x][tar.y].len+1;
                        que[i].push({di,dj});
                        inque[i][di][dj]=true;
                    }
                    else{
                        get_ans=true;
                        min_v=min(min_v,map[tar.x][tar.y].len+map[di][dj].len);
                    }
                }
            }
        }
        if(get_ans){
            printf("%d\n",min_v);
            return 0;
        }
    }

    return 0;
}