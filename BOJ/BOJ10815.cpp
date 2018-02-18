#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define pii pair<int, int>
#define mp make_pair

int main(){
    int n;
    scanf("%d",&n);
    vector<int> N(n);
    for(int i=0;i<n;++i) scanf("%d",&N[i]);
    int m;
    scanf("%d",&m);
    vector<pii> M(m);
    for(int i=0;i<m;++i){
        scanf("%d",&M[i].first);
        M[i].second=i;
    }

    // sort
    sort(N.begin(),N.end());
    sort(M.begin(),M.end());

    int ss=0;
    int ee;
    int mid;
    vector<bool> ans(m);
    for(int i=0;i<m;++i){
        // base
        if(N[ss]==M[i].first){
            ans[M[i].second]=true;
            continue;
        }

        ee=n;
        while(ss+1<ee){
            mid=(ss+ee)/2;
            if(N[mid]==M[i].first){
                ans[M[i].second]=true;
                ss=mid;
                break;
            }
            else if(N[mid]>M[i].first){
                ee=mid;
            }
            else{
                ss=mid;
            }
        }
    }
    for(int i=0;i<m;++i){
        if(ans[i]) printf("1 ");
        else printf("0 ");
    }
    printf("\n");
    return 0;
}