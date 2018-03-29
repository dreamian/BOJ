#include <cstdio> 
#include <memory.h>
using namespace std;

int n;
int mid;
int ans;
bool chk[10][10];

inline void process(int i, int j){
    bool org[10][10];
    memcpy(org,chk,sizeof(org));

    int cur_left=j, cur_right=j;
    for(int idx=i;idx<n;++idx){
        if(cur_left>=0) chk[idx][cur_left]=true;
        chk[idx][j]=true;
        if(cur_right<n) chk[idx][cur_right]=true;
        --cur_left;
        ++cur_right;
    }
    
    if(i+1==n) ++ans;
    else{
        for(int idx=0;idx<n;++idx){
            if(!chk[i+1][idx]) process(i+1,idx);
        }
    }

    memcpy(chk,org,sizeof(chk));
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        scanf("%d",&n);
        mid=n/2;
        for(int i=0;i<mid;++i) process(0,i);
        ans*=2;
        
        if(n%2==1) process(0,mid);

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}