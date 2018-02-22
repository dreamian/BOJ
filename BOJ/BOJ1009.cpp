#include <cstdio>
using namespace std;

int process(int a, int b){
    if(b==0) return 1;
    else{
        if(b%2==0) return process(a,b/2)*process(a,b/2)%10;
        else return a*process(a,(b-1)/2)*process(a,(b-1)/2)%10;
    }
}

int main(){
    int a,b;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        int tmp=process(a,b);
        if(tmp==0) tmp=10;
        printf("%d\n",tmp);
    }
    return 0;
}