#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

char target[10001];
char pattern[101];

vector<int> getPI(int len){
    vector<int> pi(len,0);
    int j=0;
    for(int i=1;i<len;++i){
        while(j>0 && pattern[i]!=pattern[j]) j=pi[j-1];
        if(pattern[i]==pattern[j]) pi[i]=++j;
    }

    return pi;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%s%s",target,pattern);
        int len_a=strlen(target);
        int len_b=strlen(pattern);
        
        vector<int> pi=getPI(len_b);

        int cnt=0;
        int idx_tar=0;
        int idx_pat=0;

        while(1){
            // 현재 진행되는 패턴과 해당 문자열의 인덱스가 일치
            while(target[idx_tar]==pattern[idx_pat]){
                ++idx_tar;
                ++idx_pat;
                if(idx_pat==len_b){
                    idx_pat=0;
                    ++cnt;
                }
                if(idx_tar==len_a) break;
            }
            if(idx_tar==len_a){
                cnt+=idx_pat;
                break;
            }
            else if(idx_pat!=0){
                cnt+=idx_pat-pi[idx_pat-1];
                idx_tar-=pi[idx_pat-1];
                idx_pat=0;
            }
            else{
                ++cnt;
                ++idx_tar;
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}