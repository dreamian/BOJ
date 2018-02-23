// 1832 ms

#include <cstdio>
#include <algorithm>
using namespace std;

int board[14][21];

// 현재 막까지 최장 길이 연속 셀의 갯수 반환 
int dp[14][21];
// 각 세로 방향의 최장 길이 계산
int longest[21];

int d,w,k;
int min_inject;

inline void Init_longest(int mem[21]){
    for(int i=1;i<=w;++i) longest[i]=mem[i];
}

// 현재 막(curD)에 약품 처리(type)를 하였을 때 조건을 만족하는지 확인
inline void DFS(int curD, int prevD_type, int type, int cnt){
    // 현재 약품 처리 횟수가 이전 탐색된 최소 처리횟수보다 같거나 큰 경우 종료
    if(cnt>=min_inject) return;

    // longest 정보 저장
    int* mem=new int[21];
    for(int i=1;i<=w;++i) mem[i]=longest[i]; 

    // 초기 조건
    if(curD==1){
        for(int i=1;i<=w;++i){
            dp[curD][i]=1;
            longest[i]=1;
        }
    }
    else{
        int prev, cur;
        for(int i=1;i<=w;++i){
            prev = prevD_type==2 ? board[curD-1][i] : prevD_type;
            cur = type==2 ? board[curD][i] : type;
            if(prev==cur){
                dp[curD][i]=dp[curD-1][i]+1;
                longest[i]=max(longest[i],dp[curD][i]);
            }
            else{
                dp[curD][i]=1;
            }
        }
    }

    // 합격 조건을 만족하면 return
    if(curD==d){
        bool pass=true;
        for(int i=1;i<=w;++i){
            if(longest[i]<k){
                pass=false;
                break;
            }
        }
        if(pass){
            min_inject=min(min_inject,cnt);
        }
        Init_longest(mem);
        delete[] mem;
        return;
    }
    DFS(curD+1,type,2,cnt);
    DFS(curD+1,type,1,cnt+1);
    DFS(curD+1,type,0,cnt+1);
    Init_longest(mem);
    delete[] mem;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        // Input
        scanf("%d%d%d",&d,&w,&k);
        min_inject=k;
        
        for(int i=1;i<=d;++i){
            for(int j=1;j<=w;++j){
                scanf("%d",&board[i][j]);
            }
        }

        // DFS, 약품 최소 투입 횟수를 구한다
        // curD : 현재 처리 막의 상태
        // prevD : 이전 처리 막의 상태
        // type 0 : 약품 A 처리, 1 : 약품 B 처리, 2 : 아무 처리 안함
        // cnt : 약품 처리 횟수
        DFS(1,-1,2,0);
        DFS(1,-1,1,1);
        DFS(1,-1,0,1);

        // Output
        printf("#%d ",tc);
        printf("%d\n",min_inject);
    }

    return 0;
}