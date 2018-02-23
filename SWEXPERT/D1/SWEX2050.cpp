#include <cstdio>
using namespace std;

char buf[200];

int main(){
    scanf("%s",buf);
    for(int i=0;;++i){
        if(buf[i]<'A' || buf[i]>'Z') return 0;
        printf("%d ",buf[i]-'A'+1);
    }
}