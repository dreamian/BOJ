#include <cstdio>
#include <queue>
using namespace std;

int n;
int map[100][100];

bool chk[100][100];

inline int search_r(int i, int j, int size){
    if(i+1==n) return size;
    else if(map[i+1][j]==0) return size;
    else return search_r(i+1,j,size+1);
}

inline int search_c(int i, int j, int size){
    if(j+1==n) return size;
    else if(map[i][j+1]==0) return size;
    else return search_c(i,j+1,size+1);
}

struct region{
    int r;
    int c;
    void scan_(int i, int j){
        r=search_r(i,j,1), c=search_c(i,j,1);
        for(int ii=i;ii<i+r;++ii)for(int jj=j;jj<j+c;++jj) chk[ii][jj]=true;
    }
    bool operator<(const region &I)const{
        if(r*c==I.r*I.c) return r>I.r;
        else return r*c>I.r*I.c;
    }
};

priority_queue<region> que;

inline void init(){
    for(int i=0;i<n;++i)for(int j=0;j<n;++j) chk[i][j]=false;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d",&n);
        init();
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) scanf("%d",&map[i][j]);

        region it;

        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            if(chk[i][j]) continue;
            if(map[i][j]==0) continue;
            it.scan_(i,j);
            que.push(it);
        }
        printf("%d ",(int)que.size());
        while(!que.empty()){
            region ans=que.top();
            printf("%d %d ",ans.r,ans.c);
            que.pop();
        }
        printf("\n");
    }
    return 0;
}