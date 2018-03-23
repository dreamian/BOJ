#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> num(n);
    vector<int> oper;
    for(int i=0;i<n;++i) scanf("%d",&num[i]);
    for(int i=0; i<4;++i){
        int a;
        scanf("%d",&a);
        for(int j=0;j<a;++j) oper.emplace_back(i);
    }
    int max_v=-1e+9;
    int min_v=+1e+9;
    do{
        int tar=num[0];
        for(int i=1;i<n;++i){
            if(oper[i-1]==0){
                tar+=num[i];
            }
            else if(oper[i-1]==1){
                tar-=num[i];
            }
            else if(oper[i-1]==2){
                tar*=num[i];
            }
            else{
                tar/=num[i];
            }
        }
        max_v=max(max_v,tar);
        min_v=min(min_v,tar);
    }while(next_permutation(oper.begin(),oper.end()));
    printf("%d\n%d\n",max_v,min_v);
}