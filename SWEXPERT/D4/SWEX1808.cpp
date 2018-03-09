#include <cstdio>
#include <algorithm>
using namespace std;

int button[10];

inline int get_len(int x){
    int len=0;
    while(x!=0){
        if(!button[x%10]) return -1;
        ++len;
        x/=10;
    }
    return len;
}

inline int recursive(int x){
    int res=1e+9;
    for(int i=2;i*i<=x;++i){
        if(x%i==0){
            int len_1=get_len(i);
            if(len_1==-1) continue;
            int len_2=get_len(x/i);
            if(len_2!=-1){
                res=min(res,len_1+len_2+1);
            }
            else{
                len_2=recursive(x/i);
                if(len_2==1e+9) continue;
                res=min(res,len_1+len_2+1);
            }
        }
    }
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        for(int i=0;i<10;++i) scanf("%d",&button[i]);
        int X;
        scanf("%d",&X);
        int one_shot=get_len(X);
        if(one_shot!=-1){
            printf("%d\n",one_shot+1);
        }
        else{
            int res=recursive(X);
            if(res==1e+9) printf("-1\n");
            else printf("%d\n",res+1);
        }
    }
    return 0;
}