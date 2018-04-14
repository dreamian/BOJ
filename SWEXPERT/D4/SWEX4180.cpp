#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int ans;
vector<int> score;
int cult[8];

inline int abs(int i, int j){
    return i-j < 0 ? j-i : i-j ;
}

// state : 각 사람들의 선택 상태를 나타냄
// cur : 현재 탐색하는 팀이 몇 번째 팀인지를 나타냄
// cur_tt : 현재 탐색 팀이 몇 명이 채워졌는지를 나타냄
// max_tt : 최대 채워지는 사람 수를 나타냄
// tot : 최대 탐색 팀의 갯수를 나타냄
void process(int state, int cur, int cur_tt, int max_tt, int tot, int picked){
    int mem=cult[cur];
    // 인원 수가 모두 찬 상태라면
    if(cur_tt==max_tt){
        for(int i=1;i<=cur-1;++i){
            if(abs(cult[i],cult[cur])<=m) continue;
            else return;
        }
        if(cur==tot){
            ++ans; return;
        }
        else{
            for(int i=1;i<=n;++i){
                if((state&(1<<i))==(1<<i)) continue;
                cult[cur+1]=score[i];
                process(state|(1<<i),cur+1,1,max_tt,tot,0);
                return;
            }
        }
    }


    // 인원 수를 채워야 한다면
    for(int i=picked+1;i<=n;++i){
        if((state&(1<<i))==(1<<i)) continue;
        cult[cur]+=score[i];
        process(state|(1<<i),cur,cur_tt+1,max_tt,tot,i);
        cult[cur]=mem;
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        scanf("%d %d",&n,&m);
        score.resize(n+1);
        for(int i=1;i<=n;++i) scanf("%d",&score[i]);
        cult[1]=score[1];
        // process
        for(int i=2;i<=n/2;++i){
            if(n%i!=0) continue;
            process(1<<1,1,1,i,n/i,1);
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}