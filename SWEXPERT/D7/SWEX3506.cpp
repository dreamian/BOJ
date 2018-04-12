#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 1e+1;
int BIT[MAX];
typedef long long ll;

int n,p;
 
void update(int i){
  while(i < n){
    BIT[i] += 1;
    i = i + (i &(-i));
  }
}
 
ll sigma(int i){
  ll res = 0;
  while(i > 0){
    res += BIT[i];
    i = i - (i &(-i));
  }
  return res;
}
 
int main(){
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d%d",&n,&p);
        vector< pair<ll,int> > arr(n);
        ll sum=0;
        for(int i=0;i<n;++i){
            BIT[i+1]=0;
            int x;
            scanf("%d",&x);
            sum+=(ll)x-p;
            arr[i].first=sum;
            arr[i].second=i+1;
        }
        sort(arr.begin(),arr.end());
        ll ans=0;
        for(int i=0;i<n;++i){
            if(arr[i].first>=0) ++ans;
            update(arr[i].second);
            ans+=sigma(arr[i].second-1);
        } 
        printf("#%d %lld\n",tc,ans);
    }
    return 0;
}