#include <cstdio>
#include <algorithm>
using namespace std;
#define max 100000

struct A{
    int num,idx;
    bool operator < (const A &zz)const{
        return num<=zz.num;
    }
}node[max+1];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&node[i].num);
        node[i].idx=i;        
    }
    sort(node,node+n); // 숫자 순으로 정렬

    int i,j,k;
    while(m--){
        scanf("%d%d%d",&i,&j,&k);

        int cnt=0;
        for(int a=0;a<n;a++){
            if(node[a].idx>=i-1 && node[a].idx<=j-1) cnt++;
            if(cnt==k) {printf("%d\n",node[a].num); break;}
        }

    }
}