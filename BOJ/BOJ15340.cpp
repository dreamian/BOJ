#include <cstdio>
#include <algorithm>
using namespace std;

const int tel[3][2]={
    {30,40},
    {35,30},
    {40,20}
};

int main(){
    int c,d;
    int ans;
    while(1){ 
        ans=1e+9;
        scanf("%d%d",&c,&d);
        if(c==0 && d==0) break;
        for(int i=0;i<3;++i){
            ans=min(ans,c*tel[i][0]+d*tel[i][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}