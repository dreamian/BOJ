#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int sum;
ll cnt;
int fac[10];
int weight[10];
int dp[19683];
int power[10];
bool visit[10];

// state는 wei_num의 추가 들어가기 바로 직전 상태를 저장
inline void search(int order, int lsum, int rsum, int state){
   if(dp[state]!=0){
       cnt+=dp[state];
       return;
   }
   else{
        if(lsum<rsum){
            return;
        }
        if(order>=n){
           dp[state]=1;
           cnt+=dp[state];
           return;
        }
        if(lsum>=ceil((double)sum/2)){
            // 남아있는 추의 갯수
            int x=n-order;
            dp[state]=(1<<x)*fac[x];
            cnt+=dp[state];
            return;
        }
        for(int i=n-1;i>=0;--i){
            if(visit[i]) continue;
            int wei_num=i;
            int left_bit=power[wei_num]*1;
            int right_bit=power[wei_num]*2;
            visit[i]=true;
            search(order+1,lsum+weight[wei_num],rsum,state+left_bit);
            search(order+1,lsum,rsum+weight[wei_num],state+right_bit);
            visit[i]=false;
        }
   }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int i=0;i<=9;++i){
        if(i==0 || i==1) fac[i]=1;
        else fac[i]=i*fac[i-1];

        if(i==0) power[i]=1;
        else power[i]=3*power[i-1];
    }
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i) visit[i]=false;
        int lim=power[n];
        for(int i=0;i<lim;++i) dp[i]=0;
        sum=0;

        for(int i=0;i<n;++i){
            scanf("%d",&weight[i]);
            sum+=weight[i];
        }
        sort(weight,weight+n);

        search(0,0,0,0);

        printf("#%d %lld\n",tc,cnt);
    }
    return 0;
}