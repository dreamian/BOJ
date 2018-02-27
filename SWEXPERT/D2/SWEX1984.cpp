#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int max_v=-1;
        int min_v=10000;
        int sum=0;
        int a;
        for(int i=0;i<10;++i){
            scanf("%d",&a);
            sum+=a;
            if(max_v<a) max_v=a;
            if(min_v>a) min_v=a;
        }
        sum-=(max_v+min_v);
        printf("#%d %d\n",tc,(int)round(sum/8.0));
    }
    return 0;
}