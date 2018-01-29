#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,m;
	scanf("%d%d",&n,&m);
	vector< vector<int> > son(n+1);
    vector<int> indeg(n+1,0);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		son[a].push_back(b);
        ++indeg[b];
	}
    priority_queue< int,vector<int>,greater<int> > que;
    for(int i=1;i<=n;++i) if(indeg[i]==0) que.push(i); 
    while(!que.empty()){
        int res=que.top();
        que.pop();
        printf("%d ",res);
        for(const auto& next : son[res]){
            if(--indeg[next]==0) que.push(next);
        }
    }

	printf("\n");
	return 0;
}