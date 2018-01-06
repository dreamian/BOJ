// Radix Sort
#include <stdio.h>

void Radix(int arr[],int len){
    int max=0;
    int idx=10;
    int temp[len];
    int tmp=0;

    for(int i=0;i<len;i++){
        temp[i]=arr[i];
        if (max <= arr[i]) max=arr[i];
    }
    while(max!=0){

        for(int i=0;i<len-1;i++){
          for(int j=(i+1);j<len;j++){
            if (temp[i]%idx>temp[j]%idx) {tmp=arr[i]; arr[i]=arr[j]; arr[j]=tmp;
                                          tmp=temp[i]; temp[i]=temp[j]; temp[j]=tmp;}
          }  
        }
        for(int k=0;k<len;k++){
          temp[k]/=10;
        }

        max/=10;
    }
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int arr[n];
    int len=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Radix(arr,len);
}