#include <cstdio>
using namespace std;

const int day[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int ans=0;
        int fm, fd, sm, sd;
        scanf("%d%d%d%d",&fm,&fd,&sm,&sd);

        for(int i=fm+1;i<sm;++i) ans+=day[i];
        if(fm==sm) ans+=sd-fd+1;
        else ans+=day[fm]-fd+sd+1;

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}