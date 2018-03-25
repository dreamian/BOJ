#include <cstdio>
#include <vector> 
using namespace std;

vector<int>::iterator it;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        vector<int> lis(1,-1);
        int idx=0;

        for(int i=0;i<n;++i){
            int tar;
            scanf("%d",&tar);

            if(tar>lis[idx]){
                lis.emplace_back(tar);
                ++idx;
            }
            else{
                it=lower_bound(lis.begin(),lis.end(),tar);
                *it=tar;
            }
        }

        printf("#%d %d\n",tc,idx);
    }
    return 0;
}