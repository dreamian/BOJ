#include <cstdio>
using namespace std;
#define row true
#define col false

int n,l;
int map[100][100];

inline bool test(int i, int step, bool isrow, int tilt){
	if(step==n-1) return true;
	int next=step+1;

	int cur_v=map[(isrow)*i+(!isrow)*step][(!isrow)*i+(isrow)*step];
	int next_v=map[(isrow)*i+(!isrow)*next][(!isrow)*i+(isrow)*next];

	if(cur_v==next_v) return test(i,next,isrow,tilt);
	else if(cur_v+1==next_v){
		// 경사로가 중첩되지 않으면 경사로 깔고 이동
		int pos=step-(l-1);
		if(pos<0 || pos>=n || pos<=tilt) return false;
		else if(tilt==-1) return test(i,next,isrow,pos);
		else{
			for(int idx=pos;idx<step;++idx){
				if(cur_v==map[(isrow)*i+(!isrow)*idx][(!isrow)*i+(isrow)*idx]) continue;
				return false;
			}
		} 
		return test(i,next,isrow,pos);
	}
	else if(cur_v==next_v+1){
		int pos=next+(l-1);
		if(pos<0 || pos>=n) return false;

		for(int idx=next+1;idx<=pos;++idx){
			if(next_v==map[(isrow)*i+(!isrow)*idx][(!isrow)*i+(isrow)*idx]) continue;
			return false;
		}
		return test(i,pos,isrow,pos);
	}
	else return false;
}

inline int process(int i){
	int res=0;

	bool a=false;
	// 행 검사
	a=test(i,0,row,-1);
	if(a) ++res;
	a=false;

	// 열 검사
	a=test(i,0,col,-1);
	if(a) ++res;

	return res;
}

int main(){
	//freopen("sample_input.txt","r",stdin);
	int ans=0;
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j) scanf("%d",&map[i][j]);
	
	for(int i=0;i<n;++i){
		ans+=process(i);
	}
	printf("%d\n",ans);
}