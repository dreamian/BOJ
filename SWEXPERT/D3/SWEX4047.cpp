#include <cstdio>
#include <cstring>
using namespace std;

char buf[1001];
int card_cnt[4];
bool card[4][14];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        for(int i=0;i<4;++i) card_cnt[i]=13;
        printf("#%d ",tc);
        scanf("%s",buf);
        int len=strlen(buf);
        int kind, num;
        bool get_err=false;

        for(int i=0;i<len;i+=3){
            if(buf[i]=='S') kind=0;
            else if(buf[i]=='D') kind=1;
            else if(buf[i]=='H') kind=2;
            else kind=3;

            num=(int)(buf[i+1]-'0')*10+(int)(buf[i+2]-'0');
            if(card[kind][num]){
                get_err=true;
                break;
            }
            card[kind][num]=true, --card_cnt[kind];
        }
        if(get_err) printf("ERROR\n");
        else{
            for(int i=0;i<4;++i) printf("%d ",card_cnt[i]);
            printf("\n");
        }
        for(int i=1;i<=13;++i) for(int j=0;j<4;++j) card[j][i]=false;
    }
    return 0;
}