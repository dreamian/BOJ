#include <cstdio> 
#include <vector>
#include <algorithm>
using namespace std;

int min_v;
int n;

// S A M U N G
vector<int> chk(6);

const char tar[6]={'S','A','M','U','N','G'};

struct Z{
    int len;
    char name[11];
    int score;
};
vector<Z> ivr;

bool test(int cur){
    for(int i=0;i<ivr[cur].len;++i){
        for(int j=0;j<6;++j){
            if(chk[j]<=0) continue;
            if(ivr[cur].name[i]==tar[j]) return true;
        }
    }

    return false;
}

void DFS(int cur, int psum){
    // 종료 조건
    if(cur==n) return;
    
    // 선택 x
    DFS(cur+1,psum);

    // 선택 o
    if(test(cur)){
        vector<int> tmp=chk;
        psum+=ivr[cur].score;
        if(psum>=min_v) return;

        for(int i=0;i<ivr[cur].len;++i){
            for(int j=0;j<6;++j){
                if(chk[j]<=0) continue;
                if(ivr[cur].name[i]==tar[j]) --chk[j];
            }
        }

        bool out_cond=true;
        for(int i=0;i<6;++i){
            if(chk[i]>0){
                out_cond=false;
                break;
            }
        }

        if(out_cond) min_v=psum;
        else DFS(cur+1,psum);
        chk=tmp;
    }

}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d\n",&t);
    for(int tc=1;tc<=t;++tc){
        // init
        for(int i=0;i<6;++i){
            if(i==0) chk[i]=2;
            else chk[i]=1;
        }

        min_v=1e+9;
        scanf("%d\n",&n);
        ivr.resize(n);
        for(int i=0;i<n;++i){
            scanf("%d\n",&ivr[i].len);
            for(int j=0;j<ivr[i].len;++j) scanf("%c ",&ivr[i].name[j]);
            scanf("%d\n",&ivr[i].score);
        }

        DFS(0,0);
        if(min_v==1e+9) min_v=-1;
        printf("#%d %d\n",tc,min_v);
    }
    return 0;
}