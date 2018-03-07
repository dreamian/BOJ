#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int cnt;
bool score[10001];
queue<int> que;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        cnt=0;
        scanf("%d",&n);
        int upto=n*100;
        for(int i=1;i<=upto;++i) score[i]=false;

        int max_v=0;

        for(int i=0;i<n;++i){
            int a;
            scanf("%d",&a);
            for(int j=1;j<=max_v;++j){
                if(score[j]) que.push(j);
            }
            while(!que.empty()){
                score[que.front()+a]=true;
                que.pop();
            }
            score[a]=true;
            max_v+=a;
            
        }

        for(int i=1;i<=upto;++i){
            if(score[i]) ++cnt;
        }

        printf("#%d %d\n",tc,cnt+1);
    }
}