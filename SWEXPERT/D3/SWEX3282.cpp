#include <cstdio> 
#include <utility> 
#include <algorithm> 
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define vol first
#define val second

const int INF=-1e+9;
pii stuff[100];
int n,v;
int dp[100][1001];

inline int DP(int i, int volume){
	if(volume<=0) return INF;
	int &res=dp[i][volume];

	if(res!=-1) return res;
	else if(i==0){
		if(stuff[i].vol<=volume) return res=stuff[i].val;
		else return 0;
	}
	else return res=max(DP(i-1,volume),stuff[i].val+DP(i-1,volume-stuff[i].vol));
}

int main(){
	//freopen("sample_input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc){
		printf("#%d ",tc);
		scanf("%d%d",&n,&v);

		// init
		for(int i=0;i<n;++i) for(int j=0;j<=v;++j) dp[i][j]=-1;
		for(int i=0;i<n;++i) scanf("%d%d",&stuff[i].vol,&stuff[i].val);
		printf("%d\n",DP(n-1,v));
	}
	return 0;
}