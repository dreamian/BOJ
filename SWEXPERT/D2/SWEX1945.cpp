#include <cstdio>
using namespace std;

const int prime[5]={2,3,5,7,11};

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int n;
        scanf("%d",&n);
        for(int i=0;i<5;++i){
            int cnt=0;
            while(n%prime[i]==0){
                ++cnt;
                n/=prime[i];
            }
            printf("%d ",cnt);
        }
        printf("\n");
    }
    return 0;
}