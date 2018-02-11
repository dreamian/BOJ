#include <cstdio>
#include <algorithm>
#include <deque>
#include <utility>
using namespace std;
#define mp make_pair
#define pii pair<int,int>

int main(){
    int n,l;
    deque< pii > que;
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;++i){
        int a;
        scanf("%d",&a);
        while(!que.empty() && que.back().first>=a) que.pop_back();
        que.push_back(mp(a,i));
        if(que.front().second<i-l+1) que.pop_front();
        printf("%d ",que.front().first);
    }
    printf("\n");
    return 0;
}