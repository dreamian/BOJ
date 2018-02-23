#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b) printf(">");
        else if(a==b) printf("=");
        else printf("<");

        printf("\n");

    }
    return 0;
}