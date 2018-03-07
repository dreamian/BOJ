#include <cstdio>
using namespace std;

int tree[100001]; 
int n,m;

inline void update(int i, int diff){
    while(i<=n){
        tree[i]+=diff;
        i += i&(-i); 
    }
}

inline int sum(int i){
    int res=0;
    while(1<=i){
        res+=tree[i];
        i -= i&(-i); 
    }
    return res;
}

inline int query(int ll, int rr){
    if(ll==1) return sum(rr);
    else return sum(rr)-sum(ll-1);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d",&n);
        for(int i=1;i<=n;++i) tree[i]=0; 
        scanf("%d",&m);
        for(int i=1;i<=n;++i){
            int diff;
            scanf("%d",&diff);
            update(i,diff);
        }
        while(m--){
            int ord,a,b;
            scanf("%d%d%d",&ord,&a,&b);
            if(ord==1) update(a,b);
            else{
                printf("%d ",query(a,b));
            }
        }
        printf("\n");
    }
    return 0;
}