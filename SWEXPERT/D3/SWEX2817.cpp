#include <cstdio> 
#include <queue>
#include <vector>
using namespace std;

int num[1001];
queue<int> proc;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n, k;
        scanf("%d%d",&n,&k);
        while(n--){
            int a;
            scanf("%d",&a);
            // que 삽입
            for(int i=1;i<=k;++i) if(num[i]) proc.push(i);
            // que 처리
            vector<int> tmp(k+1,0);
            while(!proc.empty()){
                int tar=proc.front();
                proc.pop();
                if(tar+a>k) continue;

                tmp[tar+a]+=num[tar];
            }
            for(int i=1;i<=k;++i) num[i]+=tmp[i];
            ++num[a];
        }
        printf("#%d %d\n",tc,num[k]);
        for(int i=1;i<=1000;++i) num[i]=0;
    }
}