#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[20][20];
int ans;
int state[20];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        int a;
        scanf("%d",&a);
        if(i<=j) map[i][j]=a;
        else map[j][i]+=a;
    }
    ans=1e+9;
    for(int i=n/2;i<n;++i) state[i]=1;
    do{
        int start=0;
        int link=0;
        for(int i=0;i<n;++i){
            int& res = state[i]== 0 ? start : link ;
            for(int j=i+1;j<n;++j){
                if(state[j]==state[i]) res+=map[i][j]; 
            }
        }
        int diff=start-link;
        diff = diff < 0 ? -diff : diff;
        ans=min(ans,diff);
    }while(next_permutation(state,state+n));
    printf("%d\n",ans);
}