#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define time(i) order[i].first
#define dir(i) order[i].second

int main(){
    int l;
    scanf("%d",&l);
    int ord;
    scanf("%d",&ord);
    vector< pii > order(ord);
    for(int i=0;i<ord;i++){
        // L : -1 R : 1
        int a;
        char b;
        scanf("%d %c",&a,&b);
        time(i)=a;
        if(b=='L') dir(i)=-1;
        else dir(i)=1;
    }
    
}