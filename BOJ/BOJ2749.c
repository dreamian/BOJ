#include <stdio.h>
#include <malloc.h>

typedef struct matrix{
    long long a; // 0,0
    long long b; // 0,1
    long long c; // 1,0
    long long d; // 1,1
}matrix;

matrix* Mul(matrix* a, matrix* b){
    matrix* c=(matrix *)malloc(sizeof(matrix));
    c->a=((a->a)*(b->a))+((a->b)*(b->c));
    c->b=((a->a)*(b->b))+((a->b)*(b->d));
    c->c=((a->c)*(b->a))+((a->d)*(b->c));
    c->d=((a->c)*(b->b))+((a->d)*(b->d));
    return c;
}

matrix* Pow(long long p){
    // 피보나치 행렬
    matrix* fib=(matrix *)malloc(sizeof(matrix));
    fib->a=1; fib->b=1; fib->c=1; fib->d=0; 

    if (p%2==0){ 
        return Mul(Pow(p/2),Pow(p/2));
    }
    else if (p==1){ 
        return fib;
    }
    else{
        return Mul(Mul(Pow(p/2),Pow(p/2)),fib);
    }
}


int main(void){
    long long N;
    scanf("%lld",&N);
    matrix* ans=(matrix *)malloc(sizeof(matrix));
    ans=Pow(N);

    printf("%lld ",ans->a);
    printf("%lld**\n",ans->b);
    printf("%lld ",ans->c);
    printf("%lld**\n",ans->d);

    free(ans);
}