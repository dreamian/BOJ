#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,c;

int board[10][10];

struct candidate{
	int i_dx; // 행 지표
	int j_ss; // 열 시작점
	int j_ee; // 열 끝점
	int profit; // 총 수익

	candidate() : i_dx(), j_ss(), j_ee(), profit() {}

	// 최대 수익 완전 탐색
	void calc_profit(int start, int psum, int prof){
		if(start==j_ee+1){
			profit=max(profit,prof);
			return;
		} 

		const int it=board[i_dx][start];

		// 해당 지표 비선택
		calc_profit(start+1,psum,prof);

		// 해당 지표 선택
		if(psum+it<=c){
			psum+=board[i_dx][start];
			prof=max(prof,prof+it*it);
			calc_profit(start+1,psum,prof);
		}
	}
};

int main(){
	freopen("sample_input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc){
		int ans=0;
		vector<candidate> candid(0);

		// input
		scanf("%d%d%d",&n,&m,&c);
		for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&board[i][j]);

		candidate *temp=new candidate;
		// 해당 후보군을 모두 저장
		for(int i=0;i<n;++i){
			for(int j=0;j<n-m+1;++j){
				temp->i_dx=i;
				temp->j_ss=j;
				temp->j_ee=j+m-1;
				temp->profit=0;
				temp->calc_profit(j,0,0);

				candid.push_back(*temp);
			}
		}
		delete temp;

		int sz=candid.size();
		for(int ff=0;ff<sz-1;++ff){
			for(int ss=ff+1;ss<sz;++ss){
				if(candid[ff].i_dx==candid[ss].i_dx){
					if(candid[ff].j_ss<=candid[ss].j_ee || candid[ss].j_ee<=candid[ff].j_ee) continue;
					if(candid[ff].j_ss<=candid[ss].j_ss || candid[ss].j_ss<=candid[ff].j_ee) continue;
				}
				ans=max(ans,candid[ff].profit+candid[ss].profit);
			}
		}

		// output
		printf("#%d ",tc);
		printf("%d\n",ans);
	}
	return 0;
}