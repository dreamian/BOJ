#include <cstdio>
using namespace std;

const int MAX=1000000;
int k;
// 0: not checked
// 1: false
// 2: true
// int dp[10000001][10];
int seq[100000];

inline int have_digit(int num, int digit){
    //int& res=dp[num][digit];
    int res;

    // 초기값
    res=1;
    while(num!=0){
        if(num%10==digit) return res=2;
        num/=10;
    }

    return res;
}

bool process(int num){
    int i;
    for(i=1;i<k;++i){
        //if(dp[ans+i][seq[i]]==0) have_digit(ans+i,seq[i]);
        int crit=have_digit(num+i,seq[i]);
        //if(dp[ans+i][seq[i]]==1) break;
        if(crit==1) break;
        else continue;
    }
    if(i==k) return true;
    else return false;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    //setbuf(stdout,NULL);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&k);
        //queue<int> que;

        for(int i=0;i<k;++i) scanf("%d",&seq[i]);

        // base case
        // que에 해당되는 원소를 삽입
        int ans;
        for(int i=1;i<=MAX;++i){
            //if(dp[i][seq[0]]==0) 
            int crit=have_digit(i,seq[0]);

            //if(dp[i][seq[0]]==1) continue;
            if(crit==1) continue;
            else{
                bool res=process(i);
                if(res){
                    ans=i;
                    break;
                }
                else continue;
            }
            //else que.push(i);
        }
        /*
        int ans;
        while(1){
            ans=que.front();
            que.pop();
            int i;
            for(i=1;i<k;++i){
                //if(dp[ans+i][seq[i]]==0) have_digit(ans+i,seq[i]);
                int crit=have_digit(ans+i,seq[i]);
                //if(dp[ans+i][seq[i]]==1) break;
                if(crit==1) break;
                else continue;
            }
            if(i==k) break;
        }
        */
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}