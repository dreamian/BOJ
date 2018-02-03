#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
// first : left second, second : idx
#define pii pair<int,int>


int main(){
    int t;
    scanf("%d",&t);
    priority_queue< pii,vector<pii>,greater<pii> > que;
    for(int tc=0;tc<t;++tc){
        int n;
        scanf("%d",&n);
        vector<int> right(n+1);
        vector<int> consumed(n+1);
        for(int i=1;i<=n;++i){
            pii student;
            scanf("%d%d",&student.first,&right[i]);
            student.second=i;
            que.push(student);
        }
        int curTime=que.top().first;
        while(!que.empty()){
            pii it=que.top();
            curTime=max(curTime,it.first);
            que.pop();
            if(curTime>right[it.second]) consumed[it.second]=0;
            else{
                consumed[it.second]=curTime;
                ++curTime;
            }
        }
        for(int i=1;i<=n;++i) printf("%d ",consumed[i]);
        printf("\n");
    }
}