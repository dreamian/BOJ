#include <cstdio>
using namespace std;

int mem[41]={1,1,};

int fibonacci(int n){
	if ( n <= 1) return mem[n];
	else {
		if(mem[n] > 0) return mem[n];
	}
	return mem[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(void){
    int T, n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==0) printf("1 0\n");
        else if(n==1) printf("0 1\n");
        else{
            fibonacci(n);
            printf("%d %d\n",mem[n-2],mem[n-1]);
        }
    }
    return 0;
}