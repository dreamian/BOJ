#include <cstdio>
using namespace std;

// 0 : 가위, 1 : 바위, 2 : 보
int par[3]={1,2,0};

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(par[a]==b) printf("B\n");
    else printf("A\n");
}