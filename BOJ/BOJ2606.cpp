#include <bits/stdc++.h>
using namespace std;
bool connected[101];

int main(){
    int n;
    int conn;
    scanf("%d",&n);
    scanf("%d",&conn);
    vector< pair<int,int> > spare(0);
    int sz=0;
    int cnt=0;
    connected[1]=true;
    for(int i=0;i<conn;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(connected[a] && connected[b]) continue;
        else if(connected[a]){
            connected[b]=true; cnt++;
        }
        else if(connected[b]){
            connected[a]=true; cnt++;
        }
        else{
            sz++;
            spare.resize(sz);
            spare[sz-1].first=a;
            spare[sz-1].second=b;
        }
    }
    while(1){
        sz=spare.size();
        int cont=0;
        for(int i=0;i<sz;i++){
            if(connected[spare[i].first] && connected[spare[i].second]) cont++;
            else if(connected[spare[i].first]){
                connected[spare[i].second]=true; cnt++;
                spare.erase(spare.begin()+i);
            }
            else if(connected[spare[i].second]){
                connected[spare[i].first]=true; cnt++;
                spare.erase(spare.begin()+i);
            }
            else cont++;
        }
        if(cont==sz) break;
    }
    printf("%d\n",cnt);
}