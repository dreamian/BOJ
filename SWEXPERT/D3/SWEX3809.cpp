#include <cstdio> 
using namespace std;

int n;
int min_v;
const int pow[4]={1,10,100,1000};
int seq[1000];

bool chk[1000];

inline bool process(int base){
    int from=pow[base-1];
    if(from==1) --from;

    int to=pow[base]-1;
    
    int tar;

    for(int i=0;i<n;++i){
        tar=0;
        for(int j=i,oper=base-1;j<i+base && i+base<=n;++j,--oper){

            tar+=seq[j]*pow[oper];
        }
        chk[tar]=true;
    }
    for(int i=from;i<=to;++i){
        if(chk[i]) continue;
        else{
            min_v=i;
            return true;
        }
    }
    return false;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(short tc=1;tc<=t;++tc){
        // Init
        for(int i=0;i<1000;++i) chk[i]=false;
        printf("#%d ",tc);

        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",&seq[i]);
        
        bool get_ans=false;
        for(int i=1;i<=3;++i){
            get_ans=process(i);
            if(get_ans){
                printf("%d\n",min_v);
                break;
            }
        }
    }
    return 0;
}