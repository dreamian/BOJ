#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++){

        int n;

        scanf("%*d%*d%d",&n);
        pair<int,int> temp;
        scanf("%d%d",&temp.first,&temp.second);
        int sum=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int Y=abs(y-temp.second);
            int X=abs(x-temp.first);
            if((x>temp.first && y>temp.second)||(x<temp.first && y<temp.second)){
                sum+=Y+(X>Y)*abs(X-Y);
            }
            else{
                sum+=X+Y;
            }
            temp.first=x; temp.second=y;
        }

        printf("#%d ",test);
        printf("%d\n",sum);
    }
}