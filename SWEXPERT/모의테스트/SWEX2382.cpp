#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
#define mp make_pair
#define pii pair< int,int >

// 상 하 좌 우
const int mov[4][2]={{-1,0},{1,0}, {0,-1}, {0,1}};

int sum;
int n,m,k;
// 해당 idx에 있는 미생물 군집 후보를 저장한다
vector<int> candid[100][100];
// 해당 idx에 있는 미생물 군집 후보 중 max_value를 저장한다
int max_v[100][100];

struct Z{
    pii idx;
    int num;
    int dir;
    bool merged;
    Z () : idx(), num(), dir(), merged(false) {}
};

// 약품 처리된 경우
bool out_range(int i, int j){
    if(i==n-1 || i==0 || j==n-1 || j==0) return true;
    else return false;
}

inline void process(vector<Z> &bio, int time){
    if(time>m) return;

    // 처리해야 할 idx에 대한 set 컨테이너 생성
    set<pii> proc;

    // candid, max_v 초기화
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        candid[i][j].clear();
        max_v[i][j]=0;
    }

    // 이동
    for(int i=0;i<k;++i){
        if(!bio[i].merged){
            bio[i].idx.first+=mov[bio[i].dir][0];
            bio[i].idx.second+=mov[bio[i].dir][1];
            int di=bio[i].idx.first;
            int dj=bio[i].idx.second;
            candid[di][dj].emplace_back(i);
            max_v[di][dj]=max(max_v[di][dj],bio[i].num);
            proc.insert(mp(di,dj));
        }
    }

    // 범위 밖을 벗어나는지 확인
    for(int i=0;i<k;++i){
        if(!bio[i].merged){
            int di=bio[i].idx.first;
            int dj=bio[i].idx.second;
            if(out_range(di,dj)){
                if(bio[i].dir%2==0) ++bio[i].dir;
                else --bio[i].dir;
                bio[i].num/=2;
            }
        }
    }

    // 군집이 합쳐지는 경우 확인
    for(auto idx : proc){
        if(candid[idx.first][idx.second].size()==1) continue;
        int max_val=max_v[idx.first][idx.second];
        int partsum=0;
        int who;
        for(auto it : candid[idx.first][idx.second]){
            if(bio[it].num==max_val) who=it;
            else{
                partsum+=bio[it].num;
                bio[it].merged=true;
            }
        }
        bio[who].num+=partsum;
    }

    // 다음 process 진행
    process(bio,time+1);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        // Init
        sum=0;
        scanf("%d%d%d",&n,&m,&k);
        vector<Z> bio(k);
        for(int i=0;i<k;++i){
            scanf("%d%d%d%d",&bio[i].idx.first,&bio[i].idx.second,&bio[i].num,&bio[i].dir);
            --bio[i].dir;
        }

        process(bio,1);

        for(int i=0;i<k;++i){
            if(!bio[i].merged) sum+=bio[i].num;
        }

        printf("#%d %d\n",tc,sum);
    }
}