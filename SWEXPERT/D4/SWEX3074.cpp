#include <cstdio>
#include <memory.h>

#define MAX 100000
typedef long long ll;

using namespace std;

int p[MAX+1];

int main(){
    int t;
    scanf("%d",&t);
    for(int te=1;te<=t;te++){
        memset(p,0,sizeof(p));
        int n,m;
        scanf("%d %d",&n,&m);
        

        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
        }

        ll start=0;
        ll end=1e+18;
        ll res=end;
        while(start<=end){
            ll sum=0; // 총 수용 가능 고객
            ll mid=(start+end)/2;
            for(int i=0;i<n;i++){
                sum+=mid/p[i];
            }
            if(sum>=m){
                res=res<mid?res:mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        printf("#%d %lld\n",te,res);
    }
}