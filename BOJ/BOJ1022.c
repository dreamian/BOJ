#include <stdio.h>
#include <stdlib.h>

int arr[51][5]={0,};

struct ind{
  int x;
  int y;  
};

int lenner(int n){
    int len=0;
    while(n!=0){
        n/=10;
        len++;
    }
    return len;
}

int main(void){
    int r1, c1, r2, c2;
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    int temp[4];
    temp[0]=abs(r1);
    temp[1]=abs(c1);
    temp[2]=abs(r2);
    temp[3]=abs(c2);
    int n=0;
    for(int i=0;i<4;i++){
        if(n<temp[i]){
            n=temp[i];
        }
    }
    
    struct ind ind;
    r1+=n; c1+=n; r2+=n; c2+=n;
    ind.x=n; ind.y=n;
    int i=1;

    while(i!=(2*n+1)*(2*n+1)+1){
        if(r1<=ind.y && ind.y<=r2 && c1<=ind.x && ind.x<=c2) {arr[ind.y-r1][ind.x-c1]=i;}
        i++;
        if(ind.x==n && ind.y==n){ 
            ind.x++;
        }
        else if((ind.x-n)+(ind.y-n)==0){ // 1사분면과 3사분면 경계
            if(ind.x>ind.y){
                ind.x--;
            }
            else{
                ind.x++;
            }
        }
        else if(ind.x==ind.y){  //2사분면과 4사분면, 4사분면의 경우는  오른쪽으로 이동
            if(ind.x-n<0){
                ind.y++;
            }
            else ind.x++;
        }
        else if(ind.x>n && ind.x>ind.y && (ind.x+ind.y)-2*n>0){ // 1,4사분면
            ind.y--;
        }
        else if(ind.x<n && ind.x<ind.y && (ind.x+ind.y)-2*n<0){ // 2,3사분면
            ind.y++;
        }
        else if(ind.y<n && ind.x>ind.y && (ind.x+ind.y)-2*n<0){ // 2,1 사분면
            ind.x--;            
        }
        else if(ind.y>n && ind.x<ind.y && (ind.x+ind.y)-2*n>0){
            ind.x++;            
        }
    }
    int max=0;
    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            if(max<arr[i][j]) max=arr[i][j];
        }
    }
    int len=lenner(max);

    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            int a=len-lenner(arr[i][j]);
            while(a--){printf(" ");}
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}