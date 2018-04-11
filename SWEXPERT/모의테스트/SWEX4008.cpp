#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
// +(0), -(1), *(2), /(3)
vector<int> oper;
int n, min_v, max_v;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        min_v=1e+9;
        max_v=-1e+9;

        scanf("%d",&n);
        oper.resize(n-1);
        for(int i=0, cur=0;i<4;++i){
            int a;
            scanf("%d",&a);
            while(a--) oper[cur++]=i;
        }
        num.resize(n);
        for(int i=0;i<n;++i) scanf("%d",&num[i]);
        int res=num[0];
        do{
            for(int i=1;i<n;++i){
                if(oper[i-1]==0){
                    res+=num[i];
                }
                else if(oper[i-1]==1){
                    res-=num[i];
                }
                else if(oper[i-1]==2){
                    res*=num[i];
                }
                else{
                    res/=num[i];
                }
            }
            max_v=max(max_v,res);
            min_v=min(min_v,res);
            res=num[0];
        }while(next_permutation(oper.begin(),oper.end()));
        printf("#%d %d\n",tc,max_v-min_v);
    }
    return 0;
}