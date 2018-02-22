#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){
    int t;
    scanf("%d",&t);
    double sum;
    int ans;
    for(int tc=1;tc<=t;++tc){
        sum=0;
        int a=10;
        int tmp;
        while(a--){
            scanf("%d",&tmp);
            sum+=(double)tmp;
        }
        ans=round(sum/10);
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}