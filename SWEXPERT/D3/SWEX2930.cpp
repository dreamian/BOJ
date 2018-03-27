#include <cstdio> 
#include <queue>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int ord;
        scanf("%d",&ord);

        priority_queue< int,vector<int>,less<int> > heap;
        int a,b;
        while(ord--){
            scanf("%d",&a);
            if(a==2){
                if(heap.empty()) printf("-1 ");
                else{
                    printf("%d ",heap.top());
                    heap.pop();
                }
            }
            else{
                scanf("%d",&b);
                heap.push(b);
            }
        }
        printf("\n");
    }
    return 0;
}