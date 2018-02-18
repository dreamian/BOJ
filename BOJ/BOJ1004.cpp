#include <cstdio>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int x1, y1, x2, y2;
		int cnt=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int n;
		scanf("%d",&n);
		while(n--){
			int tx,ty,tr;
			scanf("%d%d%d",&tx,&ty,&tr);
			bool cmp_ss= (tx-x1)*(tx-x1)+(ty-y1)*(ty-y1) > tr*tr ? true : false;
			bool cmp_ee= (tx-x2)*(tx-x2)+(ty-y2)*(ty-y2) > tr*tr ? true : false;
			bool possible=true;
			if((cmp_ss && cmp_ee) || (!cmp_ss && !cmp_ee)) possible=false;
			if(possible) ++cnt;
		}
		printf("%d\n",cnt);
		
	}
	return 0;
}
