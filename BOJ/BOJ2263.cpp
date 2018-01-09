#include <cstdio>
#include <vector>
using namespace std;

void Calc(vector<int> &in,vector<int> &pos, int is, int ie, int ps, int pe){
    if(ps>pe || is>ie) return;

    printf("%d ",pos[pe]);
    int idx=in[pos[pe]];
        
    // 왼쪽 구간 탐색
    Calc(in,pos,is,idx-1,ps,ps+idx-is-1);

    // 오른쪽 구간 탐색
    Calc(in,pos,idx+1,ie,ps+idx-is,pe-1);
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> in(n+1);
    vector<int> pos(n);
    
    for(int i=0;i<=n-1;i++){
        int a;
        scanf("%d",&a); //in-order : 정점의 값을 기준으로 순서를 저장
        in[a]=i;
    }
    for(int i=0;i<=n-1;i++){
        scanf("%d",&pos[i]); //post-order : 입력된 순서대로 정점을 저장
    }

    Calc(in,pos,0,n-1,0,n-1);
    printf("\n");
}