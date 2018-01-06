#include <stdio.h>
#include <math.h>

int calc(int a){
    if(a%2==0){
        return a/2;
    }
    else{
        return (a+1)/2;
    }
}

int main(void){
    int n,a,b;

    scanf("%d %d %d",&n,&a,&b);

    int r=(double)ceil(log2(n));
    int cnt=1;
  //  if((a==n || b==n) && n%2==1){
  //      printf("%d\n",r); // 마지막 round 출력
  //  }
  //  else{
        while(1){
            if(a-b==1 && a%2==0){
                break;
            }
            else if(a-b==-1 && b%2==0){
                break;
            }
            else{
                a=calc(a); b=calc(b);
            }
            cnt++;
        }
        printf("%d\n",cnt);
  //  }
}