#include <cstdio> 
using namespace std;

inline int proc(int p, int q){
    int res=1;

    while(q>0){
        if(q%2!=0) res*=p;
        p*=p;
        q/=2;
    }

    return res;
}

int main(){
    for(int tc;;){
        scanf("%d",&tc);
        int a,x;
        scanf("%d%d",&a,&x);

        printf("#%d %d\n",tc,proc(a,x));
        if(tc==10) break;
    }
    return 0;
}