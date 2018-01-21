#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n;
    int mas,sub;
    scanf("%d",&n);
    vector<int> student(n); 
    for(int i=0;i<n;i++) scanf("%d",&student[i]);
    scanf("%d%d",&mas,&sub);
    ll cnt=n;
    for(int i=0;i<n;i++){
        student[i]-=mas;
        int spare;
        if(student[i]>0){
            spare=(ceil)((double)student[i]/sub);
            cnt+=spare;
        }
    }
    printf("%lld\n",cnt);
}