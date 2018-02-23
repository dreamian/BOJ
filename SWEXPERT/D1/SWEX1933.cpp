#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    printf("1 ");
    for(int i=2;i<=n-1;++i){
        if(n%i==0) printf("%d ",i);
    }
    printf("%d\n",n);
}