#include <cstdio>
#include <cmath>
typedef unsigned long long ll;
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>(int)floor(8/log10(2))) printf("%d",m);
    else printf("%d",m%(1 << n));
    printf("\n");
}