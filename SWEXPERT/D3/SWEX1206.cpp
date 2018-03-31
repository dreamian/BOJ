#include <cstdio>
#include <algorithm>
using namespace std;

int map[1001];
int r;
int ll,rr,max_v;
int ans;

int main(){
    for(int tc=1;tc<=10;++tc){
        scanf("%d",&r);
        ans=0;
        for(int i=1;i<=r;++i) scanf("%d",&map[i]);
        for(int i=3;i<=r-2;++i){
            ll=max(map[i-1],map[i-2]);
            rr=max(map[i+1],map[i+2]);
            max_v=max(ll,rr);
            if(map[i]>max_v){
                ans+=map[i]-max_v;
            }
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}