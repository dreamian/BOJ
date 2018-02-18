#include <cstdio>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

char buf[1501];
int len;
const char kind[3]={'B','L','D'};

int dp[1500][1500][3];

int DFS(int ss, int ee, int num){
	if(ss>ee) return dp[ss][ee][num]=0;
	if(dp[ss][ee][num]!=-1) return dp[ss][ee][num];
	int res=0;
	if(buf[ss]==kind[num]) res=DFS(ss+1,ee,(num+1)%3)+1;
	if(buf[ee]==kind[num]) res=max(res,DFS(ss,ee-1,(num+1)%3)+1);
	return dp[ss][ee][num]=res;
}

int main(){
	//freopen("sample_input.txt","r",stdin);
	
	int n;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	scanf("%s",buf);
	
	len=strlen(buf);
	
	printf("%d\n",DFS(0,len-1,0));
	return 0;
}