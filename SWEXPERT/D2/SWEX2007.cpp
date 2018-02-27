#include <cstdio>
#include <cstring>
using namespace std;

char str[31];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%s",str);
        int len=strlen(str);
        int ans=len;
        // i는 마디의 길이를 나타낸다
        for(int i=1;i<=len/2+1;++i){

            // j는 문자열의 참조하는 해당 index를 가리킴
            bool possible=true;
            for(int j=i;j<len;++j){
                if(str[j]!=str[j%i]){
                    possible=false;
                    break;
                }
            }
            if(possible){
                ans=i;
                break;
            }
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}