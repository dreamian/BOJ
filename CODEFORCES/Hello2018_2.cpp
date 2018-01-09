#include <cstdio>
#include <vector>
#include <malloc.h>
using namespace std;

struct Z{
    int parent;
    vector<int> child;
}node[1001]={0,};

bool flag=true;

void Crit(int num){
    if(!flag) return;
    int sz=node[num].child.size();
    if(sz<=2) flag=false;
    else{
        int cnt=sz; 
        for(int i=0;i<sz;i++){
            if(node[node[num].child[i]].child.size()!=0){ // 자식 노드의 자식 갯수가 0이 아니라면
                cnt--; Crit(node[num].child[i]);
            }
            if(cnt<=2) {flag=false; break;}
        }
    }
}

int main(){
    int n;  
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int a;
        scanf("%d",&a);
        node[i].parent=a;
        node[a].child.push_back(i);
    }
    
    Crit(1);
    if(flag) printf("Yes\n");
    else if(!flag) printf("No\n");

}