#include <stdio.h>

int cnt_zero=0;
int cnt_one=0;

void fibonacci(int n) {
    if (n==0) {
        cnt_zero++;
    } else if (n==1) {
        cnt_one++;
    } else {
        fibonacci(n-1);
        fibonacci(n-2);
    }
}
int main(void){
    int T, n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        fibonacci(n);

        printf("%d %d\n",cnt_zero,cnt_one);
        cnt_zero=0; cnt_one=0;
    }
}