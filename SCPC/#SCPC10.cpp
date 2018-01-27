#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
#define mod 1000000007
#define mp make_pair
#define INT_MAX 100005
typedef long long ll;

int n,m,k;
int fac[INT_MAX*2], facinv[INT_MAX*2];

int min(int i, int j){
    return i<j?i:j;
}

bool compare(pair<int,int> &x, pair<int,int> &y){
	return (x.first < y.first || (x.first == y.first && x.second < y.second));
}

int mul(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y%2!=0){
            res*=x;
            res%=mod;
        }
        x*=x;
        x%=mod;
        y/=2;
    }
    return res;
}

void Init_fac(){
    fac[0]=1, facinv[0]=1;
    for(int i=1;i<=200000;++i){
        fac[i]=((ll)fac[i-1]*i)%mod;
        facinv[i]=mul(fac[i],mod-2);
    }
}

int query(int si, int sj, int ei, int ej){
    int a=ei-si;
    int b=ej-sj;
    int ff=a+b;
    int ss=min(a,b);
    int t1=fac[ff];
    int t2=(ll)facinv[ss]*facinv[ff-ss]%mod;

    return (ll)t1*t2%mod;
}

int solve(int i, vector< pair<int,int> > &X,vector<int> &dp){
    if(dp[i]!=-1) return dp[i];
    int path=query(X[i].first,X[i].second,X[k+1].first,X[k+1].second);
    int residue=0;
    for(int j=k;j>=i+1;j--){
        if(X[i].second>X[j].second) continue;
        residue=(residue+(ll)query(X[i].first,X[i].second,X[j].first,X[j].second)*solve(j,X,dp))%mod;
    }
    return dp[i]=(ll)(path-residue+mod)%mod;
}


int main(int argc, char** argv)
{
    freopen("input.txt","r",stdin);
	int T, test_case;
    Init_fac();
    setbuf(stdout, NULL);
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{   
        scanf("%d%d%d",&n,&m,&k);
        vector< pair<int,int> > barriers(0);
        vector<int> dp(2005,-1);
        barriers.push_back(mp(1,1));
        int cnt=0;
        for(int i=0;i<k;++i){
            int x, y;
            scanf("%d %d",&x,&y);
            if(x<1 || x>n || y<1 || y>m) {++cnt; continue;}
            barriers.push_back(mp(x,y));
        }
        k-=cnt;
        barriers.push_back(mp(n,m));
		
        sort(barriers.begin(),barriers.end(),compare);

		printf("Case #%d\n",test_case+1);
        printf("%d\n",solve(0,barriers,dp));
	}

	return 0;
}