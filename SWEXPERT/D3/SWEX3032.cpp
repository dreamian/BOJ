#include <cstdio> 
using namespace std;

int main(){
    int tt;
    scanf("%d",&tt);
    for(int tc=1;tc<=tt;++tc){
        int a,b;
        scanf("%d%d",&a,&b);
        //init
        int q, r1=-1, r2=a, s1, s2=1, s=0, t1, t2=0, t=1, r=b;
        while(r!=1){
            r1=r2;
            r2=r;
            s1=s2;
            s2=s;
            t1=t2;
            t2=t;

            q=r1/r2;
            r=r1-q*r2;
            s=s1-q*s2;
            t=t1-q*t2;
        }

        printf("#%d %d %d\n",tc,s,t);
    }
}