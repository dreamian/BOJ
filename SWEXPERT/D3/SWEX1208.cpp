#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=100;
int min_v, max_v;
int cnt;
int _count[101];

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        for(int i=1;i<=100;++i) _count[i]=0;
        min_v=1e+9;
        max_v=-1e+9;
        scanf("%d",&cnt);
        for(int i=0;i<MAX;++i){
            int a;
            scanf("%d",&a);
            min_v=min(min_v,a);
            max_v=max(max_v,a);
            ++_count[a];
        }
        for(int i=0;i<cnt;++i){
            if(max_v-min_v<=1) break;
            ++_count[min_v+1];
            ++_count[max_v-1];
            if(--_count[max_v]==0) while(_count[max_v]==0) --max_v;
            if(--_count[min_v]==0) ++min_v;
        }
        printf("#%d %d\n",tc,max_v-min_v);
    }
    return 0;
}