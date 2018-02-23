#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++){

        int n, m;

        scanf("%d%d",&n,&m);
        vector< pair<int, int> > kind(n);
        vector<int> p(m); 
        for(int i=0;i<n;i++){
            scanf("%d",&kind[i].first);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&p[i]);
            for(int j=0;j<n;j++){
                if(kind[j].first<=p[i]){
                    kind[j].second++; break;
                }
            }
        }
        int ans=-1;
        int max=-1;
        for(int i=0;i<n;i++){
            if(max<kind[i].second){
                max=kind[i].second;
                ans=i+1;
            }
        }

        printf("#%d ",test);
        printf("%d\n",ans);
    }
}