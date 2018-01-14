#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,pos,l,r;
    scanf("%d %d %d %d",&n,&pos,&l,&r);
    int sum=0;
    if(pos<l){
        sum+=l-pos;
        sum+=1;
        if(r!=n){
        sum+=r-l;
        sum+=1;
        }
    }
    else if(l<=pos && pos<=r){
        if(l==1 || r==n){
            if(l==1){
                if(r!=n) sum+=r-pos+1;
            }
            else if(r==n){
                if(l!=1) sum+=pos-l+1; 
            }
        }
        else{
            sum=min(pos-l,r-pos)*2+max(pos-l,r-pos)+2;
        }
    }
    else if(r<pos){
        sum+=pos-r;
        sum+=1;
        if(l!=1){
            sum+=r-l;
            sum+=1;
        }
    }
    printf("%d\n",sum);
}