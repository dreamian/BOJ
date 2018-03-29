#include <cstdio> 
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int max_v, max_vv;
int n,iter,len;
const int power[6]={1,10,100,1000,10000,100000};
vector<int> card;
vector<int> max_val;
bool out_condition;
int tc;
bool chk[10][11][1000000];

inline int get_num(vector<int> &p){
    int res=0;
    for(int i=0;i<len;++i) res+=p[i]*power[i];
    return res;
}  

inline void process(int prev_i, int prev_j, int cnt){
    if(cnt==iter){
        int res=get_num(card);
        max_v=max(max_v,res);
        if(max_v==max_vv) out_condition=true;
        return;
    }
    
    for(int i=0;i<len-1;++i){
        for(int j=i+1;j<len;++j){
            if(i==prev_i && j==prev_j) continue;
            swap(card[i],card[j]);
            int num=get_num(card);
            if(chk[tc-1][cnt][num]){
                swap(card[i],card[j]);
                continue;
            }
            else{
                chk[tc-1][cnt][num]=true;
                process(i,j,cnt+1);
                if(max_v==max_vv) return;
                swap(card[i],card[j]);
            }
        }
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(tc=1;tc<=t;++tc){
        out_condition=false;
        max_v=-1;
        card.resize(0);
        scanf("%d%d",&n,&iter);
        while(n!=0){
            int tar=n%10;
            card.emplace_back(tar);
            n/=10;
        }
        max_val=card;
        sort(max_val.begin(),max_val.end(),greater<int>());
        max_vv=get_num(max_val);
        len=card.size();
        process(-1,-1,0);
        printf("#%d %d\n",tc,max_v);
    }
    return 0;
}