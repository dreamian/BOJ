#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll mod=1000000007LL;

matrix operator * (const matrix &a,const matrix &b){
    int n=a.size();
    matrix c(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            c[i][j]%=mod;
        }
    }
    return c;
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    ll x,y;
    scanf("%lld %lld",&x,&y);
    ll order=gcd(x,y);
    //printf("%lld**\n",order);
    if(order<=1){
        printf("%lld\n",order);
        return 0;
    }

    matrix ans={{1,0},{0,1}};
    matrix a={{1,1},{1,0}};

    while(order>0){
        if(order%2==1){
            ans=ans*a;
        }
        a=a*a;
        order/=2;
    }
    printf("%lld\n",ans[0][1]);
    return 0;
}