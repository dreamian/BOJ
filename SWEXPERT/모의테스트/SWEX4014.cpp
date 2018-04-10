#include <cstdio>
using namespace std;

int map[20][20];
int n, wid, ans;

inline int height_(int i, int j, int k){
	int res;
	res = k==0 ? map[i][j] : map[j][i];
	return res;
}

inline void search(int isrow){
	int dp;
	bool ispos;
	int cur_hei, prev_hei;

	for(int i=0;i<n;++i){
		dp=1, ispos=true;
		for(int j=1;j<n;++j){
			cur_hei=height_(i,j,isrow);
			prev_hei=height_(i,j-1,isrow);
			if(cur_hei==prev_hei) ++dp;
			else if(cur_hei>prev_hei){
				if(dp>=wid && cur_hei==prev_hei+1) dp=1;
				else{
					ispos=false;
					break;
				}
			}
			else{
				int dj=j+wid-1;
				if(dj>=n || cur_hei!=prev_hei-1){
					ispos=false;
					break;
				}
				for(int k=j+1;k<=dj;++k){
					if(cur_hei==height_(i,k,isrow)) continue;
					ispos=false;
					break;
				}
				if(!ispos) break;
				else{
					dp=-1, j=dj-1;
				}
			}
		}
		if(ispos) ++ans;
	}
}

int main(){
	//freopen("sample_input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc){
		ans=0;
		scanf("%d%d",&n,&wid);
		for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&map[i][j]);
		for(int i=0;i<2;++i) search(i);
		
		printf("#%d %d\n",tc,ans);
	}
	return 0;
}