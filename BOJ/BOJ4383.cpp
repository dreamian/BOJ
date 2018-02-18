#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int n;
        int a = scanf("%d",&n);
        if(a==EOF) break;
        vector<bool> chk(n-1,false);
        bool jolly=true;
        int prev;
        int next;
        scanf("%d",&prev);
        for(int i=1;i<=n-1;++i){
            scanf("%d",&next);
            int vv=abs(prev-next);
            if(vv>n-1 || vv<1 || chk[vv]){
                jolly=false;
                break;
            }
            chk[vv]=true;
            prev=next;
        }
        jolly ? printf("Jolly\n") : printf("Not jolly\n");
        while(getchar()!='\n');
    }
}