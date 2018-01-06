#include <stdio.h>

int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        for(int i=1;;i++){
            if(b%a==0) {printf("%d\n",b/a); break;} 
            else if(a*i>b){
                    a=a*i-b;
                    b=b*i;
                    i=1;
            }
            
        }
    }
}