#include <cstdio>
using namespace std;

bool visit[5001];
int love[5001];

bool triangle(int i){
    bool triangle=false;
    int p=-1, pp=-1;
    int next=love[i];

    while(1){
        visit[i]=true;
        if(next==pp) return true;
        if(visit[next] && next!=pp) return false;
        
        pp=p;
        p=i;
        i=next;
        next=love[i];
    }
    return triangle;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&love[i]);
    bool ispos=false;
    for(int i=2;i<=n;++i){
        if(visit[i]) continue;
        ispos=triangle(i);
        if(ispos) break;
    }
    ispos ? printf("YES\n") : printf("NO\n");
}