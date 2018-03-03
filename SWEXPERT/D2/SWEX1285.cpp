#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        // first : 거리 차이, second : 사람 수
        pii ans=mp(1e+9,-1);
        scanf("%d",&n); 
        for(int i=0;i<n;++i){
            int pos;
            scanf("%d",&pos);
            if(pos<0) pos*=-1;
            if(ans.first>pos){
                ans.first=pos;
                ans.second=1;
            }
            else if(ans.first==pos) ++ans.second;
        }

        printf("#%d %d %d\n",tc,ans.first,ans.second);
    }
    return 0;
}