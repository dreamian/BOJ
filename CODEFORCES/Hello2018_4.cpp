#include <bits/stdc++.h>
using namespace std;

struct Z{
    int k, time, addr;
    Z() : k(), time(), addr() {}

    void scan(int _addr){
        scanf("%d%d", &k, &time);
        addr=_addr+1;
    }
    
    bool operator < (const Z &P) const{
        return time<P.time;
    }
};

const int N=200001;

Z p[N];

int n,T;
int sz=0;
int ans[N];

bool solve(int mid){
    sz=0;
    int sum=0;
    for(int i=0;sz<mid && i<n;i++){
        if(p[i].k>=mid){
        sum+=p[i].time; ans[sz++]=p[i].addr;
        } 
    }
    return sum<=T && sz==mid;
}

int main() {
    scanf("%d %d",&n,&T);

    for(int i=0;i<n;i++){
        p[i].scan(i);   
    }
    sort(p,p+n);
    int start=0;
    int end=n+1;
    while(start+1<end){
        int mid=(start+end+1) >> 1;
        bool flag=solve(mid);

        flag?start=mid:end=mid;
    }
    solve(start);
    printf("%d\n%d\n",start,start);
    for(int i=0;i<start;i++) printf("%d ",ans[i]);
    printf("\n");

}