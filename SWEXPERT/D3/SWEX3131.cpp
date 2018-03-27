#include <cstdio>
using namespace std;

bool no_prime[1000001];

int main(){
    //freopen("output.txt","w",stdout);
    int upto=1000;
    printf("2 ");
    for(register int i=3;i<=upto;i+=2){
        if(no_prime[i]) continue;
        printf("%d ",i);
        register int s=i+i*2;
        while(s<1000000){
            no_prime[s]=true;
            s+=i*2;
        }
    }
    for(register int i=upto+1;i<1000000;i+=2) if(!no_prime[i]) printf("%d ",i);
    printf("\n");
}