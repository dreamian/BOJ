#include <cstdio> 
using namespace std;

int len;
int ans;
char map[8][9];

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        ans=0;
        scanf("%d",&len);
        int upto=7-len+1;
        for(int i=0;i<8;++i) scanf("%s",map[i]);
        // column search
        for(int i=0;i<8;++i){
            for(int j=0;j<=upto;++j){
                int ll=j, rr=j+len-1;
                bool palin=true;
                while(ll<=rr){
                    if(map[i][ll]==map[i][rr]) ++ll,--rr;
                    else{
                        palin=false;
                        break;
                    }
                }
                if(palin) ++ans;
            }
        }
        // row search
        for(int j=0;j<8;++j){
            for(int i=0;i<=upto;++i){
                int ll=i, rr=i+len-1;
                bool palin=true;
                while(ll<=rr){
                    if(map[ll][j]==map[rr][j]) ++ll,--rr;
                    else{
                        palin=false;
                        break;
                    }
                }
                if(palin) ++ans;
            }
        }

        printf("#%d %d\n",tc,ans);
    }
    return 0;
}