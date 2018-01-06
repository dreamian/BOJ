#include <stdio.h>
#include <math.h>

int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    int c=sqrt(a); if(c*c<a) c+=1; 
    int d=sqrt(b);
    int min=c*c;
    int sum=0;
    for(int i=c;i<=d;i++){
        sum+=i*i;
    }
    if (sum==0) printf("-1\n");
    else printf("%d\n%d\n",sum,min);

}