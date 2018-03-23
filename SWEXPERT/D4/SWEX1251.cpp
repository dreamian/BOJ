#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
#define plli pair<ll,int>
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

double e;
int n;

pii island[1000];
bool chk[1000];
priority_queue< plli,vector<plli>,greater<plli> > que;

ll make_dist(pii a, pii b){
    ll A=a.x-b.x;
    ll B=a.y-b.y;
    return A*A+B*B;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&n);
        for(int i=0;i<n;++i) chk[i]=false;
        for(int i=0;i<n;++i) scanf("%d",&island[i].x);
        for(int i=0;i<n;++i) scanf("%d",&island[i].y);
        scanf("%lf",&e);
        ll ans=0;

        que.push(mp(0,0));

        while(!que.empty()){
            plli tar=que.top();
            que.pop();
            if(chk[tar.second]) continue;

            chk[tar.second]=true;
            ans+=tar.first;

            for(int i=0;i<n;++i){
                if(chk[i]) continue;
                ll dist=make_dist(island[tar.second],island[i]);
                que.push(mp(dist,i));
            }
        }
        ans=round((double)ans*e);
        printf("#%d %lld\n",tc,ans);
    }
    return 0;
}