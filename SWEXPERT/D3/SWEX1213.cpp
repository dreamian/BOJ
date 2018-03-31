#include <cstdio> 
#include <cstring>
using namespace std;

char s[11];
char t[1001];

int main(){
    for(int tc;;){
        scanf("%d",&tc);
        scanf("%s %s",s,t);
        int len_S=strlen(s);
        int len_T=strlen(t);
        int cnt=0;
        for(int i=0;i<len_T;++i){
            bool get_ans=true;
            int cur=0;
            for(int j=i;j<i+len_S;++j){
                if(s[cur++]==t[j]) continue;
                get_ans=false;
                break;
            }
            if(get_ans) ++cnt;
        }
        printf("#%d %d\n",tc,cnt);
        if(tc==10) return 0;
    }
}