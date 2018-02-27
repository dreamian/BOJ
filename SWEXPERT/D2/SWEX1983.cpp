#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const char credit[10][2]={
    {'A','+'},
    {'A','0'},
    {'A','-'},
    {'B','+'},
    {'B','0'},
    {'B','-'},
    {'C','+'},
    {'C','0'},
    {'C','-'},
    {'D','0'}
};

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        
        int n,k;
        scanf("%d%d",&n,&k);
        vector<int> db(n);
        for(int i=0;i<n;++i){
            int mid,fin,assign;
            scanf("%d%d%d",&mid,&fin,&assign);
            mid*=35;
            fin*=45;
            assign*=20;
            db[i]=mid+fin+assign;
        }
        int rank=1;
        for(int i=0;i<n;++i){
            if(i+1==k) continue;
            if(db[k-1]<db[i]) ++rank;
        }
        rank=ceil(rank/(double)(n/10));
        printf("#%d %c%c\n",tc,credit[rank-1][0],credit[rank-1][1]);
    }
    return 0;
}