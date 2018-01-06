#include <stdio.h>
#include <math.h>

int main(void){
    int r;
    scanf("%d",&r);
    double a=pow(r,2)*3.141593;
    double b=2*pow(r,2);
    printf("%.6lf\n%.6lf\n",a,b);
}