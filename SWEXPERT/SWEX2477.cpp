#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int ans, n , m , k , a, b;
bool chk[1001];

struct customer{
    int num;
    int time;
    int used_a;
};

bool recept_cmp(const customer &a, const customer &b){
    if(a.time == b.time) return a.num<b.num;
    else return a.time<b.time;
}

bool repair_cmp(const customer &a, const customer &b){
    if(a.time == b.time) return a.used_a<b.used_a;
    else return a.time<b.time;
}

inline void process_(vector<int> &A, vector<int> &B, vector<customer> &C){
    //// in reception desk
    
    // customer setting in reception desk
    sort(C.begin(),C.end(),recept_cmp);

    // in desk, first : time, second : desk #
    priority_queue< pii,vector<pii>,greater<pii> > que;
    for(int i=1;i<=n;++i) que.push(mp(C[0].time,i));

    for(int i=0;i<k;++i){
        while(que.top().first<C[i].time){
            pii temp=que.top();
            que.pop();
            temp.first=C[i].time;
            que.push(temp);
        }

        pii desk=que.top();
        que.pop();

        if(desk.second==a) chk[C[i].num]=true;

        C[i].used_a=desk.second;
        C[i].time=desk.first+A[desk.second];

        que.push(mp(desk.first+A[desk.second],desk.second));
    }

    while(!que.empty()) que.pop();
    
    // customer setting in repair desk
    sort(C.begin(),C.end(),repair_cmp);
    for(int i=1;i<=m;++i) que.push(mp(C[0].time,i));

    for(int i=0;i<k;++i){
        while(que.top().first<C[i].time){
            pii temp=que.top();
            que.pop();
            temp.first=C[i].time;
            que.push(temp);
        }

        pii desk=que.top();
        que.pop();
        if(desk.second==b && chk[C[i].num]) ans+=C[i].num;

        que.push(mp(desk.first+B[desk.second],desk.second));
    }

}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        scanf("%d%d%d%d%d",&n,&m,&k,&a,&b);

        // Init chk array
        for(int i=1;i<=k;++i) chk[i]=false;

        vector<customer> C(k);
        vector<int> A(n+1,0);
        vector<int> B(m+1,0);
        // in recept
        for(int i=1;i<=n;++i) scanf("%d",&A[i]);

        // in repair
        for(int i=1;i<=m;++i) scanf("%d",&B[i]);

        // customer
        for(int i=0;i<k;++i){
            scanf("%d",&C[i].time);
            C[i].num=i+1;
        }
        process_(A,B,C);

        printf("#%d ",tc);
        ans > 0 ? printf("%d\n",ans) : printf("-1\n");
    }
    return 0;
}