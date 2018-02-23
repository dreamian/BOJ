#include <cstdio>
#include <cstring>
using namespace std;

char buf[81];

int main(){
    scanf("%s",buf);
    int sz=strlen(buf);
    for(int i=0;i<sz;++i){
        if(buf[i]>='a' && buf[i]<='z'){
            buf[i]+='A'-'a';
        }
        printf("%c",buf[i]);
    }
    printf("\n");
    return 0;
}