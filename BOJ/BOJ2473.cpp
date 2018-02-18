#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(){
    int n;
    scanf("%d",&n);
    vector<int> liquid(n);
    for(int i=0;i<n;++i) scanf("%d",&liquid[i]);
    sort(liquid.begin(),liquid.end());

    int ans[3]={-1,-1,-1};
    ll opti_val=3e+9+1;
    int picked=-1;

    for(int i=0;i<n;++i){
        picked=liquid[i];
        int ss=0+(i == 0);
        int ee=n-1-(i == n-1);
        while(ss<ee){
            ll search=(ll)picked+liquid[ss]+liquid[ee];
            if(opti_val>abs(search)){
                opti_val=abs(search);
                ans[0]=picked;
                ans[1]=liquid[ss];
                ans[2]=liquid[ee];
                if(opti_val==0) break;
            }
            if(search<0) ss=ss+1+(ss+1 == i);
            else ee=ee-1-(ee-1 == i);
        }
        if(opti_val==0) break;
    }

    sort(ans,ans+3);
    // Output
    for(int i=0;i<3;++i) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}