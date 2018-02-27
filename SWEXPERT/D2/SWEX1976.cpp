#include <cstdio>
using namespace std;

int main(){
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int hh=a+c;
        int mm=b+d;
        hh+=mm/60;
        mm%=60;
        hh%=12;
        if(hh==0) hh+=12;
        printf("#%d %d %d\n",tc,hh,mm);
    }
    return 0;
}