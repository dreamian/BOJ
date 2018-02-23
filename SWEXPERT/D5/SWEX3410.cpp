#include <cstdio>
#include <vector>
using namespace std;
#define mp make_pair

int west[10001];
int sum[10001];
char buf[10001];

int main(){
	//freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc){
		// ans -> 해당 경계 지표
		// key -> 서방 문화에서 동방 문화가 나오는 횟수와 동방 문화에서 서방 문화가 나오는 횟수의 합의 최소
		int key=1e+9;
		int ans;
		int n,m;

		scanf("%d %d",&n,&m);
		
		// Initiation
		for(int i=1;i<=n;++i){
			west[i]=0;
			sum[i]=0;
		}

		for(int cul=1;cul<=m;++cul){
			scanf("%s",buf);
			for(int i=0;i<n;++i){
				if(buf[i]=='W') ++west[i+1];
			}
		}

		for(int num=1;num<=n;++num) sum[num]+=west[num]+sum[num-1];

		for(int bd=0;bd<=n;++bd){
			// 경계 이하의 총 문화의 갯수
			int west_=(m*bd)-sum[bd];
			int east_=sum[n]-sum[bd];
			if(west_+east_>=key) continue;
			key=west_+east_;
			ans=bd;
		}

		printf("#%d ",tc);
		printf("%d %d\n",ans,ans+1);

	}
	return 0;
}