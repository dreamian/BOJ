#include <cstdio> 
#include <cstring> 
using namespace std;
char buf[51];

int cnt;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        cnt=0;
        scanf("%s",buf);
        int len=strlen(buf);
        bool proc=false;
        for(int i=0;i<len;++i){
            if(!proc){
                if(buf[i]=='1'){
                    proc=true;
                    ++cnt;
                }
            }
            else{
                if(buf[i]!=buf[i-1]) ++cnt;
            }
        }
        printf("#%d %d\n",tc,cnt);
    }
    return 0;
}