#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;

int a[20];
int b[20];

inline void process(){
    int max_v=-1e+9;

    int ll= n > m ? n : m;
    int ss= n < m ? n : m;

    int ee=ll-ss;

    int sum;

    for(int i=0;i<ee+1;++i){
        sum=0;
        for(int j=0;j<ss;++j){
            sum+=a[i+j]*b[j];
        }
        if(sum>max_v) max_v=sum;
    }

    printf("%d\n",max_v);

}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i) scanf("%d",n>m ? &a[i] : &b[i]);
        for(int i=0;i<m;++i) scanf("%d",n<m ? &a[i] : &b[i]);
        process();
    }
    return 0;
}