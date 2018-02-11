#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=5e+5+1;

char str[MAX];

vector<int> make_SA(int len){

    // Init
    vector<int> suf(len);
    vector<int> group(len);
    vector<int> newGroup(len);
    int d;
    for(int i=0;i<len;++i){
        suf[i]=i;
        group[i]=str[i];
    }

    // Process
    for(d=1;;d*=2){
        // lamma expression
        auto cmp = [&group, d, len](int i, int j){
            if(group[i]!=group[j]) return group[i]<group[j];
            else if(i+d>=len || j+d>=len) return i>j;
            return group[i+d]<group[j+d];
        };

        // sort
        sort(suf.begin(),suf.end(),cmp);
        
        newGroup[suf[0]]=0;
        int max_v=-1;
        for(int i=1;i<len;++i){
            newGroup[suf[i]]=newGroup[suf[i-1]]+cmp(suf[i-1],suf[i]);
            max_v=max(max_v,newGroup[suf[i]]);

        }
        if(max_v==len-1) break;
        group=newGroup;
    }

    return suf;
}

vector<int> make_LCP(vector<int> &suf, int len){
    // Init
    vector<int> lcp(len-1);
    vector<int> pos(len);
    // pos[i]는 suf의 값이 i인 접미사가 sa 배열에서 몇 번째에 위치하는지를 가리킴
    for(int i=0;i<len;++i) pos[suf[i]]=i;

    for(int i=0,k=0;i<len;++i,k=max(k-1,0)){
        if(pos[i]==len-1) continue;

        for(int j=suf[pos[i]+1];str[i+k]==str[j+k];++k);
        lcp[pos[i]]=k;
    }


    return lcp;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    scanf("%s",str);
    int len=strlen(str);
    // Suffix Array
    auto suf=make_SA(len);
    for(int i=0;i<len;++i) printf("%d ",suf[i]+1);
    printf("\n");

    // LCP
    auto lcp=make_LCP(suf,len);
    printf("x ");
    for(int i=0;i<len-1;++i) printf("%d ",lcp[i]);
    printf("\n");
}