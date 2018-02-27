#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int cnt=0;
        int num=i;
        while(num!=0){
            if((num%10)%3==0 && num%10!=0) ++cnt;
            num/=10;
        }
        if(cnt!=0){
            for(int i=0;i<cnt;++i) printf("-");
            printf(" ");
        } 
        else printf("%d ",i);
    }
    printf("\n");
    return 0;
}