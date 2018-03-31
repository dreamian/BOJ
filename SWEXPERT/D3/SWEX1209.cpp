#include <cstdio>
#include <algorithm>
using namespace std;

int map[100][100];
int dp_col[100];
int dp_cross_a;
int dp_cross_b;
int dp_row;
int max_v;

int main(){
    for(int tc;;){
        scanf("%d",&tc);
        for(int i=0;i<100;++i) dp_col[i]=0;
        dp_cross_a=0, dp_cross_b=0, dp_row=0, max_v=0;

        for(int i=0;i<100;++i){
            for(int j=0;j<100;++j){
                scanf("%d",&map[i][j]);
                dp_row+=map[i][j];
                dp_col[j]+=map[i][j];
                if(i==j) dp_cross_a+=map[i][j];
                if(i+j==99) dp_cross_b+=map[i][j];
            }
            max_v=max(max_v,dp_row);
            dp_row=0;
        }
        max_v=max(max_v,dp_cross_a);
        max_v=max(max_v,dp_cross_b);
        for(int i=0;i<100;++i) max_v=max(max_v,dp_col[i]);

        printf("#%d %d\n",tc,max_v);
        if(tc==10) return 0;
    }
}