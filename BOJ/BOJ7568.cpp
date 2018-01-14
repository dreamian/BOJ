#include <bits/stdc++.h>
using namespace std;
#define weight(n,i) n[i].second.first
#define high(n,i) n[i].second.second
#define rank(n,i) n[i].first

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int, pair <int,int> > > p(n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&weight(p,i),&high(p,i));
    }
    for(int i=0;i<n;i++){
        int rank=1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(weight(p,i)<weight(p,j) && high(p,i)<high(p,j)) rank++;
        }
        rank(p,i)=rank;
    }
    for(int i=0;i<n;i++) printf("%d ",rank(p,i));
    printf("\n");
}

