#include <cstdio> 
using namespace std;

const int MAX=100;

int len;
int ans;
char map[MAX][MAX+1];

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc;;){
        scanf("%d",&tc);
        for(int i=0;i<MAX;++i) scanf("%s",map[i]);
        len=100;
        while(1){
            int upto=99-len+1;
            bool get_ans;
            // column search
            for(int i=0;i<MAX;++i){
                for(int j=0;j<=upto;++j){
                    int ll=j, rr=j+len-1;
                    get_ans=true;
                    while(ll<=rr){
                        if(map[i][ll]==map[i][rr]) ++ll,--rr;
                        else{
                            get_ans=false;
                            break;
                        }
                    }
                    if(get_ans){
                        ans=len;
                        break;
                    }
                }
                if(get_ans) break;
            }
            if(get_ans) break;
            // row search
            for(int j=0;j<MAX;++j){
                for(int i=0;i<=upto;++i){
                    int ll=i, rr=i+len-1;
                    get_ans=true;
                    while(ll<=rr){
                        if(map[ll][j]==map[rr][j]) ++ll,--rr;
                        else{
                            get_ans=false;
                            break;
                        }
                    }
                    if(get_ans){
                        ans=len;
                        break;
                    }
                }
                if(get_ans) break;
            }
            if(get_ans) break;
            --len;
        }
        printf("#%d %d\n",tc,ans);
        if(tc==10) break;
    }
    return 0;
}