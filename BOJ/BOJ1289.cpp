#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
#define son(i) i.first
#define wei(i) i.second
#define mod 1000000007
#define mp make_pair
typedef long long ll;

vector< pair<int,int> > connect[100001];

int sum=0;

int DFS(int root, int par){
    int res=0;
    int part=0;
    for(auto next : connect[root])if(son(next)!=par){
        // base case
        int A=(ll)(DFS(son(next),root)+1)*wei(next)%mod;
        
        // case 1 : son-root 경로만을 저장
        res=(res+(ll)A)%mod;
        sum=(sum+(ll)A)%mod;

        // case 2 : son-root-son 경로 저장
        if(part!=0) sum=(sum+part*(ll)A)%mod;
        part=(part+(ll)A)%mod;

    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        connect[a].push_back(mp(b,w));
        connect[b].push_back(mp(a,w));
    }
    DFS(1,-1);
    printf("%d\n",sum);
}