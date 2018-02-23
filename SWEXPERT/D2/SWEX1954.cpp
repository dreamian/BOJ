#include <cstdio>
using namespace std;

short min(short a, short b, short c, short d){
    a=a<b?a:b;
    a=a<c?a:c;
    return a<d?a:d;
}


short f(short i, short j,short n){
    short p=min(i,j,n-i-1,n-j-1);
    if(i<=j) return i+j+1-2*p+4*(p*n-p*p);
    else return 4*(n-1-2*p)-(i+j-1-2*p)+4*(p*n-p*p);
}

int main(){
    short t;
    scanf("%hd",&t);
    for(short te=1;te<=t;te++){
        short n;
        scanf("%hd",&n);

        
        printf("#%hd\n",te);
        for(short i=0;i<n;i++){
            for(short j=0;j<n;j++){
                printf("%hd ",f(i,j,n));
            }
            printf("\n");
        }
    }
    
}