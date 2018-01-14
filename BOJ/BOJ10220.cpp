#include <cstdio>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    int n;
    scanf("%d",&n);
    if(n==1 || n==2 || n==3 || n==6) printf("0\n");
    else if(n==4) printf("2\n");
    else printf("1\n");
    }
}