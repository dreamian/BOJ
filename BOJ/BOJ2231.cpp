#include <bits/stdc++.h>
using namespace std;
int arr[1000054]={0,};

int main(){
    int cmp;
    scanf("%d",&cmp);
    int copy=cmp;
    int sz=0;
    while(copy!=0){
        copy/=10;
        sz++;
    }
    for(int i=cmp-9*sz;i<=cmp;i++){
        int sum=i;
        int part=i;
        while(part!=0){
            sum+=part%10;
            part/=10;
        }
        if(arr[sum]==0) arr[sum]=i;
    }
    printf("%d\n",arr[cmp]);
}