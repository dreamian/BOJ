#include <cstdio>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc){
		int a,b,c;
		int ans;
		scanf("%d%d%d",&a,&b,&c);
		if(a==b) ans=c;
		else if(a==c) ans=b;
		else ans=a;
		
		printf("#%d %d\n",tc,ans);	
	}
	return 0;
}
