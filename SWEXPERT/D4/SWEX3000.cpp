#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

const int mod=20171109;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        priority_queue< int,vector<int>,less<int> > max_heap;
        priority_queue< int,vector<int>,greater<int> > min_heap;
        int a, ff;
        scanf("%d%d",&a,&ff);
        max_heap.push(ff);
        ll sum=0;
        while(a--){
            int ia,ib;
            scanf("%d%d",&ia,&ib);
            max_heap.push(ia);
            min_heap.push(ib);
            if(max_heap.top()>min_heap.top()){
                int a=max_heap.top();
                int b=min_heap.top();
                max_heap.pop();
                max_heap.push(b);
                min_heap.pop();
                min_heap.push(a);
            }
            sum+=max_heap.top();
            sum%=mod;
        }

        printf("#%d %lld\n",tc,sum);
    }
    return 0;
}