#include <cstdio>
using namespace std;

struct node{
    int ll;
    int rr;
    node () : ll(-1), rr(-1) {}
}N[1000000];

inline void post_order(int root){
    if(N[root].ll!=-1) post_order(N[root].ll);
    if(N[root].rr!=-1) post_order(N[root].rr);
    printf("%d\n",root);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int root;
    scanf("%d",&root);
    // IN
    while(1){
        int n;
        int cmp=root;
        int tt=scanf("%d",&n);
        if(tt==EOF) break;
        while(1){
            if(cmp<n){
                if(N[cmp].rr!=-1){
                    cmp=N[cmp].rr;   
                }
                else{
                    N[cmp].rr=n;
                    break;
                }
            }
            else{
                if(N[cmp].ll!=-1){
                    cmp=N[cmp].ll;
                }
                else{
                    N[cmp].ll=n;
                    break;
                }
            }
        }
    }

    // OUT
    post_order(root);
    return 0;
}