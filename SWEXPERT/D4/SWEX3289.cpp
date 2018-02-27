#include <cstdio>
using namespace std;

const int MAX=1e+6+1;
int n,m;

int root[MAX];

inline int find_root(int i){
    if(i==root[i]) return i;
    root[i]=find_root(root[i]);
    return root[i];
}

inline void union_(int a, int b){
    int root_a=find_root(a);
    int root_b=find_root(b);
    root[root_a]=root[root_b];
}

inline void find_(int a, int b){
    if(find_root(a)==find_root(b)) printf("1");
    else printf("0");
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i) root[i]=i;
        for(int i=0;i<m;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a==0) union_(b,c);
            else find_(b,c);
        }
        printf("\n");
    }  
    return 0;
}