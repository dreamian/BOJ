#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

bool compare(int a,int b){
    return abs(a)<abs(b);
}
deque<int> deq;

int order[100005];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, k;
        int a,b;
        deq.clear();
        memset(order,0,sizeof(order));

        cin >> n >> l >> k;

        for(int i=1;i<=n;i++){ // 각 개미의 id를 deq으로 관리
            cin >> a >> b;
            deq.push_back(b);
            order[i]=a;
            order[i]*=b>0?1:-1;
            if(order[i]>0) order[i]=l-order[i];
        }
        sort(order+1,order+n+1,compare);
        int ans=0;

        for(int cnt=1;cnt<=k;cnt++){
            if(order[cnt]+order[cnt+1]==0 && cnt<n){
                if(deq.back()>deq.front()){
                    ans=deq.front(); deq.pop_front();     
                }
                else{
                    ans=deq.back(); deq.pop_back();
                }
            }
            else{
                if(order[cnt]>0){
                    ans=deq.back(); deq.pop_back();
                }
                else{
                    ans=deq.front(); deq.pop_front();
                }
            } 
        }
        cout << ans << endl;
    }
}