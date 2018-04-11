#include <cstdio> 
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

int n;
int min_v;
pii stu_idx[10];
pii step_idx[2];
int step_len[2];
int dist[10][2];

int sz_stu, sz_step;

vector<int> step_1;
vector<int> step_2;

inline int abs(int i, int j){
    return i-j < 0 ? j-i : i-j ;
}

inline void process(int state){
    // get wait queue
    step_1.resize(0);
    step_2.resize(0);

    for(int i=0;i<sz_stu;++i){
        if((state&(1<<i))!=(1<<i)) step_1.emplace_back(dist[i][0]);
        else step_2.emplace_back(dist[i][1]);
    }

    sort(step_1.begin(),step_1.end());
    sort(step_2.begin(),step_2.end());

    int sz_ff=step_1.size();
    int sz_ss=step_2.size();

    // in step 1,
    for(int i=0;i<sz_ff;++i){
        // 앞의 3번째 사람의 탈출 여부 확인
        if(i-3>=0){
            if(step_1[i-3]<=step_1[i]) step_1[i]+=step_len[0];
            else step_1[i]=step_1[i-3]+step_len[0];
        }
        // 초기 세 명은 앞 사람의 영향을 받지 않는다
        else step_1[i]+=step_len[0];
    }
    // in step 2,
    for(int i=0;i<sz_ss;++i){
        // 앞의 3번째 사람의 탈출 여부 확인
        if(i-3>=0){
            if(step_2[i-3]<=step_2[i]) step_2[i]+=step_len[1];
            else step_2[i]=step_2[i-3]+step_len[1];
        }
        // 초기 세 명은 앞 사람의 영향을 받지 않는다
        else step_2[i]+=step_len[1];
    }
    
    int end_time;
    if(sz_ff==0 || sz_ss==0){
        if(sz_ff==0) end_time=step_2[sz_ss-1];
        else end_time=step_1[sz_ff-1];
    }
    else end_time=max(step_1[sz_ff-1],step_2[sz_ss-1]);
    
    min_v=min(min_v,end_time);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        min_v=1e+9;
        scanf("%d",&n);
        
        sz_stu=0, sz_step=0;

        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            int a;
            scanf("%d",&a);
            // student
            if(a==1){
                stu_idx[sz_stu++]=mp(i,j);
            }
            // step
            if(a>1){
                step_len[sz_step]=a;
                step_idx[sz_step++]=mp(i,j);
            }
        }

        for(int i=0;i<sz_stu;++i){
            for(int j=0;j<sz_step;++j){
                dist[i][j]=abs(stu_idx[i].x,step_idx[j].x)+abs(stu_idx[i].y,step_idx[j].y);
                ++dist[i][j];
            }
        }

        int upto=1<<sz_stu;
        for(int i=0;i<upto;++i) process(i);
        //process(48);

        printf("#%d %d\n",tc,min_v);
    }
    return 0;
}