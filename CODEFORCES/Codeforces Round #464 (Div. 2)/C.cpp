#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define mp make_pair
#define pii pair<int,int>

int main(){
    //freopen("sample_input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    vector<int> dp(n,0);
    
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    
    dp[0]=a[0];
    for(int i=1;i<n;++i) dp[i]=dp[i-1]+a[i];
    
    int s,f;
    scanf("%d%d",&s,&f);
    const int sz=f-s;
    // first : capacity , second : first time zone local time
    pii ans=mp(-1,1e+9);
    for(int i=0;i<n;++i){
        // index i has start time s
        int tot_sz=0;
        int fs=s-i;
        if(fs<=0) fs+=n;
        if(s<=fs && fs<f) tot_sz+=dp[f-fs-1];
        
        if(i!=0){
            int ee=i+sz-1;
            if(ee>=n) ee=n-1;
            tot_sz+=dp[ee]-dp[i-1];
        }

        if(ans.first==tot_sz){
            int ss=s-i;
            if(ss<=0){
                ss+=n;
            }
            // update
            if(ans.second>ss){
                ans=mp(tot_sz,ss);
            }
        }
        else if(ans.first<tot_sz){
            int ss=s-i;
            if(ss<=0){
                ss+=n;
            }
            // update
            ans=mp(tot_sz,ss);
        } 
    }
    printf("%d\n",ans.second);
    return 0;
}