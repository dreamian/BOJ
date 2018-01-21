#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define node_num(i) candid.first
#define dir(i) candid.second

struct N{
    int parent;
    int left;
    int right;
    int level;
    int l_sz;
    int r_sz;
    int idx;
    // 구조체 초기화
    N() : parent(-1), left(-1), right(-1), level(-1), l_sz(0), r_sz(0), idx(0) {}
};

deque <int> query;

int lv_max=0;

void Init_lv(vector<N> &node, int root, int lv){
    lv_max=lv_max>lv?lv_max:lv;
    node[root].level=lv;
    if(node[root].left!=-1) Init_lv(node,node[root].left,lv+1);
    if(node[root].right!=-1) Init_lv(node,node[root].right,lv+1);

    if(node[root].left==-1 && node[root].right==-1) query.push_back(root);
}

void inorder(vector<N> &node,int root, vector< pair<int,int> > &ans,int indi){

    int cmp;
    if(node[root].left!=-1){
        indi-=node[node[root].left].r_sz+1;
        node[node[root].left].idx+=indi;
        cmp=ans[node[node[root].left].level].first;
        ans[node[node[root].left].level].first=cmp<node[node[root].left].idx?cmp:node[node[root].left].idx;
        inorder(node,node[root].left,ans,indi);
        indi+=node[node[root].left].r_sz+1;
    }
    cmp=ans[node[root].level].first;
    ans[node[root].level].first=cmp<node[root].idx?cmp:node[root].idx;
    cmp=ans[node[root].level].second;
    ans[node[root].level].second=cmp>node[root].idx?cmp:node[root].idx;
        
    if(node[root].right!=-1){
        indi+=node[node[root].right].l_sz+1;
        node[node[root].right].idx+=indi;
        cmp=ans[node[node[root].right].level].second;
        ans[node[node[root].right].level].second=cmp>node[node[root].right].idx?cmp:node[node[root].right].idx;
        inorder(node,node[root].right,ans,indi);
    }

}

int main(){
    int n;
    scanf("%d",&n);
    vector<N> node(n+1);
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        node[a].left=b;
        if(b!=-1) node[b].parent=a;
        node[a].right=c;
        if(c!=-1) node[c].parent=a;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(node[i].parent!=-1) continue;
        Init_lv(node,i,1);
        root=i;
        break;
    }

    while(!query.empty()){
        int a=query.front();
        query.pop_front();
        if(node[a].parent==-1) continue;

        if(node[node[a].parent].left==a){
            node[node[a].parent].l_sz=node[a].l_sz+node[a].r_sz+1;
        }
        else node[node[a].parent].r_sz=node[a].l_sz+node[a].r_sz+1;
        
        if(query.back()==node[a].parent) continue;
        query.push_back(node[a].parent);
    }
    
    vector< pair<int,int> > ans(lv_max+1,make_pair(1e+9,-(1e+9)));
    inorder(node,root,ans,0);
    pair<int,int> anss(make_pair(0,0));
    for(int i=1;i<=lv_max;i++){
        if(anss.second<ans[i].second-ans[i].first+1){
            anss.second=ans[i].second-ans[i].first+1;
            anss.first=i;
        }
    }

    printf("%d %d\n",anss.first,anss.second);

    return 0;
}