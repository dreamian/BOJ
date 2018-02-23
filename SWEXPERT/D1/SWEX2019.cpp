#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    n+=1;
    int a=1;
    while(n--){
        printf("%d ",a);
        a*=2;
    }
}