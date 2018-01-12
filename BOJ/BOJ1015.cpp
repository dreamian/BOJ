#include <bits/stdc++.h>
using namespace std;

bool cmp1(const pair<int,int> &p1,const pair<int,int> &p2){
    if(p1.second!=p2.second) return p1.second<p2.second;
    return p1.first<p2.first;
}

bool cmp2(const pair<int,int> &p1,const pair<int,int> &p2){
    return p1.first<p2.first;
}

int main(){
    int n;
    scanf("%d",&n);
    vector< pair<int,int> > P(n);
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].second);
        P[i].first=i;
    }
    sort(P.begin(),P.end(),cmp1);
    for(int i=0;i<n;i++) P[i].second=i;
    sort(P.begin(),P.end(),cmp2);
    for(int i=0;i<n;i++) printf("%d ",P[i].second);
}