#include <cstdio>
#include <utility>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second

int n;
ll ans;

// 0~n-1로 넘버링된 각 지렁이들의 좌표값 저장
pii worm[20];

inline void process(int state){
    pii vec_sum=mp(0,0);
    for(int idx=0;idx<n;++idx){
        int t=(1<<idx);
        // selected
        if((t&state)==t){
            vec_sum.x+=worm[idx].x;
            vec_sum.y+=worm[idx].y;
        }
        // unselected
        else{
            vec_sum.x-=worm[idx].x;
            vec_sum.y-=worm[idx].y;
        }
    }
    ll sum=(ll)vec_sum.x*vec_sum.x+(ll)vec_sum.y*vec_sum.y;
    ans = ans < sum ? ans : sum;
}

inline bool possible(int state){
    int cnt=0;
    for(int t=1;;t*=2){
        if(t==(1<<n)) break;
        if(cnt>n/2) break;
        if((t&state)==t) ++cnt;
    }

    if(cnt==n/2) return true;
    else return false;
}

inline void query(){
    int tar=n/2;
    int ss=(1<<tar)-1;
    int ee=(1<<n)-1;
    for(int i=ss;i<=ee;++i){
        if(possible(i)) process(i);
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=1e+11;
        scanf("%d",&n);
        
        for(int i=0;i<n;++i){
            scanf("%d%d",&worm[i].x,&worm[i].y);
        }

        query();

        printf("#%d %lld\n",tc,ans);
    }
    return 0;
}