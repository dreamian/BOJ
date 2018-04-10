#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX=2e+6;

int cam[10000];
bool visit[MAX+1];
int n,k;
int len;
priority_queue< int,vector<int>,less<int> > que;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        len=0;
        for(int i=0;i<MAX+1;++i) visit[i]=false;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;){
            int a;
            scanf("%d",&a);
            if(visit[a+1000000]){
                --n;
                continue;
            }
            visit[a+1000000]=true;
            cam[i]=a;
            ++i;
        }
        sort(cam,cam+n);
        for(int i=0;i<n-1;++i){
            que.push(cam[i+1]-cam[i]);
        }
        for(int i=0;i<k-1 && !que.empty();++i) que.pop();
        while(!que.empty()){
            len+=que.top(), que.pop();
        }
        printf("#%d %d\n",tc,len);
    }
    return 0;
}