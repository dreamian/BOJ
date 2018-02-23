#include <bits/stdc++.h>

int main(){
    int t;
    scanf("%d",&t);
    for(int te=1;te<=t;te++){
        int sum=0;
        int a;
        for(int i=0;i<5;i++){
            scanf("%d",&a);
            if(a>=40) sum+=a/5;
            else sum+=8;
        } 

        printf("#%d %d\n",te,sum);
    }
}