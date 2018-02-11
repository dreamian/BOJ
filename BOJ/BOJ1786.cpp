#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define INT_MAX 1e+7

char T[(int)INT_MAX+1];
char P[(int)INT_MAX+1];

inline void myscanf(char *string){
    int i=0;
    char idx;
    do{
        int t=scanf("%c",&idx);
        if(t==EOF || idx=='\n') break;
        string[i++]=idx;
    }while(1);
}

vector<int> getPI(){
    int m=strlen(P);
    vector<int> pi(m,0);
    
    int j=0;
    for(int i=1;i<=m-1;++i){
        while(j>0 && P[i]!=P[j]) j=pi[j-1];

        if(P[i]==P[j]){
            pi[i]=++j;
        }
    }
    return pi;
}

vector<int> KMP(){
    vector<int> matched;
    auto pi=getPI();
    int n=strlen(T);
    int m=strlen(P);
    int j=0;
    for(int i=0;i<n;++i){
        while(j>0 && T[i]!=P[j]) j=pi[j-1];
        if(T[i]==P[j]){
            if(j==m-1){
                matched.emplace_back(i-m+1);
                j=pi[j];
            }
            else ++j;
        }
    }
    return matched;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    myscanf(T);
    myscanf(P);
    auto matched=KMP();
    int cnt=matched.size();
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i) printf("%d ",matched[i]+1);
    printf("\n");
    return 0;
}