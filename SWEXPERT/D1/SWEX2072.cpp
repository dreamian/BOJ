#include <cstdio>
using namespace std;

int sum;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int a=10;
        sum=0;
        while(a--){
            int b;
            scanf("%d",&b);
            if(b%2==1) sum+=b;
        }
        printf("#%d %d\n",tc,sum);
    }
    return 0;
}