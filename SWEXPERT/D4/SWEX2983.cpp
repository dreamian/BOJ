#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=200001;

char str[MAX];
int len;
int sa[MAX];
int group[MAX];
int temp[MAX];
int rrank[MAX];

void getSA(){
    // group은 맨 마지막 접미사의 경우 예외 처리를 위해 +1
    for(int i=0;i<len;++i){
        sa[i]=i;
        group[i]=str[i]-'a';
    }
    int t=1;
    auto cmp=[&t](const int i, const int j){
        if(group[i]==group[j]) return group[i+t]<group[j+t];
        else return group[i]<group[j];
    };
    while(t<=len){
        group[len]=-1;
        sort(sa,sa+len,cmp);
        temp[0]=0;
        int cnt=0;
        for(int i=1;i<len;++i){
            // group이 다르다면,
            if(cmp(sa[i-1],sa[i])){
                ++cnt;
                temp[sa[i]]=temp[sa[i-1]]+1;
            }
            // group이 같다면
            else temp[sa[i]]=temp[sa[i-1]];
        }
        if(cnt==len) break;
        for(int i=0;i<len;++i) group[i]=temp[i];
        t<<=1;
    }
}

inline int query(){
    int max_v=-1;
    for(int i=0;i<len;++i) rrank[sa[i]]=i;
    int val=0;
    for(int i=0;i<len;++i){
        int k=rrank[i];
        if(k){
            int j=sa[k-1];
            while(str[j+val]==str[i+val]) ++val;
            max_v=max(max_v,val);
            if(val) --val;
        }
    }
    return max_v;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&len);
        scanf("%s",str);
        getSA();
        int ans=query();
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}