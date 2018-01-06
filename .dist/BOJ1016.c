#include <stdio.h>
#include <math.h>
#include <memory.h>
typedef long long ll;

ll IsPrime[1000001];
int Prime[100001];

int main(void){
    //freopen("input.txt","r",stdin);
    ll min, max;
    scanf("%lld %lld",&min,&max);
    memset(IsPrime,0,sizeof(IsPrime));
    memset(Prime,0,sizeof(Prime));

    Prime[0]=2;
    int real=1;
    for(ll i=3;i*i<=max;i+=2){
        if(IsPrime[i]==0){
        Prime[real++]=i;
        for(ll j=i*i;j<=(int)sqrt(max)+1;j+=2*i){
            if(IsPrime[j]==0) IsPrime[j]=1;
        } 
        }
    }
    // 에라토스테네스의 체 과정 종료. Prime에 소수가 들어감

    int cnt=max-min+1; // 전체 범위 구간의 수

    // 이후의 IsPrime은 min~max 범위의 수를 나타내는 데에 활용한다.

    memset(IsPrime,0,sizeof(IsPrime));
    

    for(int i=0;i<=max-min;i++){
        IsPrime[i]=min+i;
    }
    for(int i=0;i<real;i++){
        ll key=Prime[i]*Prime[i];
        for(int j=0;j<=max-min;j++){
            if(IsPrime[j]!=0){
                if(IsPrime[j]%key==0){
                    for(int k=j;k<=max-min;k+=key){  
                        if(IsPrime[k]!=0){cnt--;
                                          IsPrime[k]=0; 
                        }
                    }
                }
            }
        }
    }

    printf("%d\n",cnt);

}