#include <cstdio> 
#include <utility>
using namespace std;
#define pii pair<int,int> 
#define mp make_pair
#define x first
#define y second

inline pii binary_(int k){
    int ll=1, rr=141, mid;
    
    pii idx;

    while(ll<rr){
        mid=(ll+rr)/2;
        if((mid*mid+mid)/2>=k){
            rr=mid;
        }
        else{
            ll=mid+1;
        }
    }

    idx=mp(rr,1);
    int diff=(rr*rr+rr)/2-k;
    idx.x-=diff, idx.y+=diff;

    return idx;
}

int p,q;
pii ans;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d%d",&p,&q);
        pii a=binary_(p);
        pii b=binary_(q);
        ans=mp(a.x+b.x,a.y+b.y);
        printf("%d\n",(ans.y*ans.y-3*ans.y)/2+ans.x*(ans.y-1)+1+ans.x*(ans.x+1)/2);
    }
    return 0;
}