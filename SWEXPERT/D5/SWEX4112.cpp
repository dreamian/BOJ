#include <cstdio>
#include <utility> 
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

const int MAX=142;
pii a,b;
int diff_r, diff_c;

inline int abs_sum(int i, int j){
    i = i < 0 ? -i : i ;
    j = j < 0 ? -j : j ;
    return i+j;
}

inline pii get_idx(int a){
    pii res;
    int ll=0, rr=142, mid;
    while(ll<=rr){
        mid=(ll+rr)/2;
        if((mid*mid-mid)/2+1>a) rr=mid-1;
        else{
            res.x=mid;
            ll=mid+1;
        }
    }

    res.y=a-(res.x*res.x-res.x)/2;

    return res;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int _a,_b;
        scanf("%d%d",&_a,&_b);
        if(_a<_b) swap(_a,_b);
        else if(_a==_b){
            printf("0\n");
            continue;
        }
        a=get_idx(_a);
        b=get_idx(_b);
        diff_r=a.x-b.x;
        diff_c=a.y-b.y;
        if(a.y>=b.y) printf("%d\n",diff_r+(b.y<a.y-diff_r)*(diff_c-diff_r));
        else printf("%d\n",abs_sum(diff_r,diff_c));
    }
    return 0;
}