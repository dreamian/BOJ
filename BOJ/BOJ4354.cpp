#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define MAX 1e+7

char buf[(int)MAX+1];
vector<string> pref;

inline void make_pref(int length, int size){
    int idx=size-length;
    pref.emplace_back(buf+idx);
}

int main(){
    while(1){
        scanf("%s",buf);

        // 종료
        if(buf[0]=='.') return 0;

        int sz=strlen(buf);

        // 해당 buf 길이의 약수의 갯수만큼 약수의 길이로 생성
        for(int i=1;i<=sz;++i){
            if(sz%i==0) make_pref(i,sz);
        }
        int n=-1;
        for(int i=0;i<pref.size();++i){
            bool flag=false;
            int len=pref[i].size();
            n=sz/len;
            for(int j=0;j<n-1;++j){
                for(int k=0;k<len;++k){
                    if(pref[i][k]!=buf[k+len*j]){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag) break;
        }

        printf("%d\n",n);
        pref.clear();
    }
    return 0;
}