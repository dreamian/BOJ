#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

int n;
ll cont[1000];
ll copyd[1000];

inline int ABS(int i, int a){
    int res = i-a;
    res = res < 0 ? -res : res;
    return res;
}

inline void search(int crit, int end){

    ll tot=0;
    for(int i=0;i<n;++i){
        tot+=cont[i];
        copyd[i]=cont[i];
    }

    // left
    int amount=crit;
    if(amount){
        ll sum=tot*(amount/n);
        amount%=n;
        int cur;
        for(cur=n-1;amount;--cur,--amount){
            sum+=copyd[cur];
        }
        ++cur;
        cur%=n;

        for(int i=0;i<n;++i){
            cont[i]+=sum;
            sum-=copyd[cur];
            sum+=copyd[(i+n)%n];
            cur = (cur+1)%n;
        }
    }
    // right
    amount=end-1-crit;
    if(amount){
        ll sum=tot*(amount/n);
        amount%=n;
        int cur;
        for(cur=n-1;amount;--cur,--amount){
            sum+=copyd[cur];
        }
        ++cur;
        cur%=n;

        for(int i=0;i<n;++i){
            cont[i]+=sum;
            sum-=copyd[cur];
            sum+=copyd[(i+n)%n];
            cur = (cur+1)%n;
        }
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int x,y,z,a,b,c;
        scanf("%d%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c,&n);
        for(int i=0;i<n;++i) cont[i]=0;
        
        // Pre-query
        for(int i=0;i<x;++i) ++cont[ABS(i,a)%n];

        search(b,y);
        search(c,z);

        // Output
        for(int i=0;i<n;++i) printf("%lld ",cont[i]);
        printf("\n");
    }
    return 0;
}