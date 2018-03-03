#include <cstdio>
using namespace std;

int que;

inline void process(char a, int iter){
    for(int i=0;i<iter;++i){
        printf("%c",a);
        ++que;
        if(que==10){
            printf("\n");
            que=0;
        }
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d\n",tc);
        int n;
        scanf("%d\n",&n);
        que=0;

        for(int i=0;i<n;++i){
            char a;
            int iter;
            scanf("%c %d\n",&a,&iter);
            process(a,iter);        
        }
        printf("\n");
    }
    return 0;
}