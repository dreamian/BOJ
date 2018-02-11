#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define X(i) student[i].idx.first
#define Y(i) student[i].idx.second
#define step_X(i) step[i].idx.first
#define step_Y(i) step[i].idx.second
#define step_size(i) step[i].size
#define mp make_pair
#define INF 1e+9

int n;
int ans;
int board[11][11];

struct Z{
    pii idx;
    bool exit;
    bool enter;
    Z () : idx(), exit(false), enter(false) {}
    // step 0 -> 1번째 계단 이용
    // step 1 -> 2번째 계단 이용
};

struct Y{
    pii idx;
    int size;
};

queue<int> wait_steps[2];
queue<pii> steps[2];

inline void Init_que(){
    for(int i=0;i<2;++i){
        while(!wait_steps[i].empty()){
            wait_steps[i].pop();
        }
        while(!steps[i].empty()){
            steps[i].pop();
        }
    }
}

inline void DFS(vector<Z> &student, vector<Y> &step, int step_info, int cnt, int T){
    if(ans<=T) return;

    int crit=0;
    for(int i=0;i<2;++i){
        int sz=steps[i].size();
        for(int j=0;j<sz;++j){
            auto info=steps[i].front();
            steps[i].pop();
            if(++info.first==step_size(i)){
                student[info.second].exit=true;
                continue;
            }
            steps[i].push(info);
        }
        while(!wait_steps[i].empty() && steps[i].size()<3){
            steps[i].push(mp(0,wait_steps[i].front()));
            wait_steps[i].pop();
        }    
    }
    // 도착하지 않은 경우
    for(int i=0;i<cnt;++i){
        // 완전 탈출의 경우
        if(student[i].exit){
            ++crit;
            continue;
        }
        // 계단에 있는 경우
        if(student[i].enter) continue;

        // 해당 학생의 계단 정보 생성
        int step_n=( step_info & (1<<i) ) == 0 ? 0 : 1; 
        
        int di=X(i)-step_X(step_n);
        int dj=Y(i)-step_Y(step_n);
        if(di!=0){
            if(di>0){
                --X(i);
            }
            else{
                ++X(i);
            }
        }
        else{
            if(dj>0){
                --Y(i);
            }
            else{
                ++Y(i);
            }
        }
        if(X(i)==step_X(step_n) && Y(i)==step_Y(step_n)){
            wait_steps[step_n].push(i);
            student[i].enter=true;
        }    
    }


    if(crit==cnt){
        ans=min(ans,T);
        return;
    }
    else{
        DFS(student,step,step_info,cnt,T+1);
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=INF;

        vector<Z> student(0);
        vector<Y> step(0);

        scanf("%d",&n);
        Z tmp;
        Y tt;
        int cnt=0;
        int step_i=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",&board[i][j]);
                // student
                if(board[i][j]==1){
                    tmp.idx.first=i;
                    tmp.idx.second=j;
                    student.emplace_back(tmp);
                    ++cnt;
                }
                // step
                else if(board[i][j]>1){
                    tt.idx=mp(i,j);
                    tt.size=board[i][j];
                    step.emplace_back(tt);
                }
            }
        }
        vector<Z> origin=student;
        
        for(int i=0;i<(1 << (n+1));++i){
            DFS(origin,step,i,cnt,1);
            origin=student;
            Init_que();
        }
        
        printf("#%d %d\n",tc,ans);
    }
}