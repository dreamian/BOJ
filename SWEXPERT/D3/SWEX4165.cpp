#include <cstdio>
using namespace std;
typedef long long ll;

ll fac[17];
int ans;

inline ll comb(int n, int r){
    return fac[n]/(fac[n-r]*fac[r]);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    // memoization
    fac[0]=1;
    for(int i=1;i<=16;++i) fac[i]=fac[i-1]*i;
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        int tar;
        scanf("%d",&tar);
        for(int i=2;i<=tar/2;++i){
            if(tar%i==0){
                int upto=tar/i;
                int it=tar-1;
                ll res=1;
                for(int j=0;j<upto;++j){
                    res*=comb(it,i-1);
                    it-=i;    
                }
                ans+=res;
            }
        }

        printf("#%d %d\n",tc,ans+1);
    }
    return 0;
}