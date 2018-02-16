#include <cstdio>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int x1, y1, r1, x2, y2, r2;
		scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
		int dist=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		int r_plus=(r1+r2)*(r1+r2);
		int r_minus=(r1-r2)*(r1-r2);
		if(x1==x2 && y1==y2 && r1==r2){
			printf("-1\n");
			continue;
		}
		if(r_minus==dist || dist==r_plus) printf("1\n");
		else if(r_minus<dist && dist<r_plus) printf("2\n");
		else printf("0\n");
	}
	return 0;
}
