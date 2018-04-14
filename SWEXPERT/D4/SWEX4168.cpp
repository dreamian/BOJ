#include <cstdio> 
#include <utility>
using namespace std;
#define pii pair<int,int>
#define cost first
#define val second

int max_v, n;
int ans, ans_s;

pii info[25];

void DFS(int num, int psum, int max_val, int state){
    // 종료 조건
    if(num==n){
        if(ans<max_val){
            ans=max_val;
            ans_s=state;    
        }
        return;
    }
    
    // 비선택
    DFS(num+1,psum,max_val,state);

    // 선택
    if(psum+info[num].cost<=max_v) DFS(num+1,psum+info[num].cost,max_val+info[num].val,state|(1<<num));
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=-1;
        scanf("%d %d",&max_v,&n);
        for(int i=0;i<n;++i) scanf("%d%d",&info[i].cost,&info[i].val);
        DFS(0,0,0,0);

        printf("#%d ",tc);
        for(int i=0;i<n;++i){
            if((ans_s&(1<<i))==(1<<i)) printf("%d ",i);
        }
        printf("%d\n",ans);
    }
    return 0; 
}