#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int n, max_cost;
pii couns[15];

inline void process(int cost, int day){
    // out
    if(day>=n){
        max_cost=max(max_cost,cost);
        return;
    }

    process(cost,day+1);

    int del=couns[day].first;
    if(day+del<=n) cost+=couns[day].second;
    process(cost,day+del);
}

int main(){
    scanf("%d",&n);
    max_cost=0;
    for(int i=0;i<n;++i){
        scanf("%d",&couns[i].first);
        scanf("%d",&couns[i].second);
    }

    process(0,0);

    printf("%d\n",max_cost);
}