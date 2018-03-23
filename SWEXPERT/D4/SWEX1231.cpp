#include <cstdio>
#include <vector>
using namespace std;

struct N{
    char val;
    int left;
    int right;
    N(): left(-1), right(-1) {}
};

inline void in_order(int root, vector<N>& node){
    if(node[root].left!=-1) in_order(node[root].left,node);
    printf("%c",node[root].val);
    if(node[root].right!=-1) in_order(node[root].right,node);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        printf("#%d ",tc);
        int n;
        scanf("%d\n",&n);
        vector<N> node(n+1);
        for(int i=0;i<n;++i){
            int tar;
            char val;
            scanf("%d %c ",&tar,&val);
            node[tar].val=val;
            // left
            int ll;
            if(tar*2<=n){
                scanf("%d ",&ll);
                node[tar].left=ll;
            }
            // right
            int rr;
            if(tar*2+1<=n){
                scanf("%d\n",&rr);
                node[tar].right=rr;  
            } 
        }
        in_order(1,node);
        printf("\n");
    }
    return 0;
}