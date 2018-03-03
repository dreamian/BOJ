#include <cstdio>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int cnt[101];

int main(){
    //freopen("sample_input.txt","r",stdin);
    while(1){
        int tc;
        int a=scanf("%d",&tc);
        if(a==EOF) break;
        // first : score
        // second : preq. val
        pii ans=mp(-1,-1);
        for(int i=0;i<1000;++i){
            int score;
            scanf("%d",&score);
            if(ans.second<++cnt[score]) ans=mp(score,cnt[score]);
            else if(ans.second==cnt[score] && ans.first<score) ans=mp(score,cnt[score]);
        }

        printf("#%d %d\n",tc,ans.first);
        // init
        for(int i=0;i<=100;++i) cnt[i]=0;
    }
    return 0;
}