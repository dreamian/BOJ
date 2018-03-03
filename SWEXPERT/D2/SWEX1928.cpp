#include <cstdio>
using namespace std;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d\n",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        while(1){
            bool exit=false;
            int bit=0;
            for(int i=3;i>=0;--i){
                char a;
                int ee=scanf("%c",&a);
                if(a=='\n' || ee==EOF){
                    exit=true;
                    break;
                }
                int target;

                if('A'<=a && a<='Z') target=a-'A';
                else if('a'<=a && a<='z') target=a-'a'+26;
                else if('0'<=a && a<='9') target=a-'0'+52;
                else if(a=='+') target=62;
                else target=63;

                bit+=(target << 6*i);
            }
            if(exit) break;
            int idx=(1<<23);
            int ascii;
            for(int i=0;i<3;++i){
                ascii=0;
                for(int j=7;j>=0;--j){
                    if((bit&idx) == idx) ascii+=(1<<j);
                    idx/=2;
                }
                printf("%c",ascii);
            }
        }
        printf("\n");
    }
    return 0;
} 