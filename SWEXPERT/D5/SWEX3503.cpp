#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int ans;
int n;
        
int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&n);
        vector<int> high(n);
        for(int i=0;i<n;++i) scanf("%d",&high[i]);
        sort(high.begin(),high.end());
        // base case
        ans=high[1]-high[0];

        // 0 2 4 ..
        for(int i=2;i<n;i+=2){
            ans=max(ans,high[i]-high[i-2]);
        }
        // 1 3 5 ..
        for(int i=3;i<n;i+=2){
            ans=max(ans,high[i]-high[i-2]);
        }

        // last case
        ans=max(ans,high[n-1]-high[n-2]);

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}