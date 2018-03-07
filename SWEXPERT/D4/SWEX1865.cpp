#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=1<<16;

int n;
double prob[16][16];
double dp[16][MAX];

inline void Init(){
    int upto=1<<n;
    for(int i=0;i<n;++i) for(int j=0;j<upto;++j) dp[i][j]=-1;
}

double process(int row, int state){
    if(row==n) return 1;

    double& ret=dp[row][state];

    if(ret!=-1) return ret;

    // find max dp
    for(int i=0;i<n;++i){
        if((state&(1<<i)) == (1<<i) ) continue;
        ret=max(ret,prob[row][i]*process(row+1,state|(1<<i)));
    }

    return ret;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&n);
        Init();

        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            int a;
            scanf("%d",&a);
            prob[i][j]=(double)a/100;
        }

        printf("#%d %f\n",tc,100*process(0,0));
    }
}