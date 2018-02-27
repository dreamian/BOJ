#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define loser 0
#define winner 1

bool prob_test(ll ss, ll ee, int state){
    if(ss==1 || ee==1){
        return state;
    }
    else{
        if(state==loser){    
            return prob_test(ss/2,ss-1,state^1);
        }
        else{   
            return prob_test(ceil(ss/2.0),ss-1,state^1);
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        ll n;
        scanf("%lld",&n);
        
        bool win=prob_test(n/2+1,n,loser);

        win ? printf("Alice\n") : printf("Bob\n") ;
    }
    return 0;
}