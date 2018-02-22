#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=(1<<21)-1;

int data[MAX];
int dp[MAX];
int sum[MAX];

int main(){
	int max_high;
	scanf("%d",&max_high);
	int n=(1<<(max_high+1))-1;
	for(int i=2;i<=n;++i) scanf("%d",&data[i]);

	for(int i=max_high-1;i>=0;--i){
		for(int j=(1<<i);j<(1<<(i+1));++j){
			int ll=2*j;
			int rr=ll+1;
			dp[j]=max(dp[ll]+data[ll],dp[rr]+data[rr]);
			sum[j]=sum[ll]+sum[rr]+dp[j]-dp[ll]+dp[j]-dp[rr];
		}
	}

	printf("%d\n",sum[1]);
	return 0;
}