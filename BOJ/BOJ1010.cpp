#include <cstdio>
using namespace std;
typedef long long ll;

inline int comb(int n, int r){
    ll res=1;
    r = r > n/2 ? n-r : r;
    if(r==1) return n;
    else if(r==0) return 1;

    for(int i=n,cnt=r,j=r;;){
        bool flg1=false, flg2=false;
        if(cnt>0){
            flg1=true;
            res*=i;
            --i;
            --cnt;
        }
        if(res%j==0 && j>1){
            flg2=true;
            res/=j;
            --j;
        }
        if(!flg1 && !flg2) break;
    }

    return (int)res;
}

int main(){
    int t;
    scanf("%d",&t);
    int a,b;
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",comb(b,a));
    }
    return 0;
}