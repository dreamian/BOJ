#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int l,u,x,ans;
        scanf("%d%d%d",&l,&u,&x);
        if(x<l){
            ans=l-x;
        }
        else if(l<=x && x<=u){
            ans=0;
        }
        else{
            ans=-1;
        }
        printf("#%d %d\n",tc,ans);
    }
}