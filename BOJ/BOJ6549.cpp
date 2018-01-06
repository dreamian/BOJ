#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

ll area=-1;

void Init_Seg(vector<int> &h, vector<int> &tree,int node, int start, int end){
    if(start==end) tree[node]=start;
    else{
        int mid=(start+end)/2;
        Init_Seg(h,tree,2*node,start,mid);
        Init_Seg(h,tree,2*node+1,mid+1,end);
        if(h[tree[2*node]]<=h[tree[2*node+1]]){
            tree[node]=tree[2*node];
        }
        else{
            tree[node]=tree[2*node+1];
        }
    }
}

void Calc(vector<int> &tree,int node, int start, int end){
    area=area>tree[node]*(end-start+1)?area:tree[node]*(end-start+1);
}   

// search the minimum height in range form i to j
void Search(vector<int> &h, vector<int> &tree, int node, int start, int end,int i, int j){
    while(node!=tree.size()){
        int idx=-1;
        if(start==i && end==j){
            idx=tree[node];
        }


        int mid=(start+end)/2;
        Calc(tree,node,start,end);
        // 탐색된 index에 대해 왼쪽 탐색
        Search(h,tree,2*node,start,mid,i,j);
        // 탐색된 index에 대해 오른쪽 탐색
        Search(h,tree,2*node+1,mid+1,end,i,j);

    }
}

int main(void){
    int n;
    while(n!=0){
        scanf("%d",&n);
        // allocatiing a vector of height information of each histogram
        vector<int> h(n);
        // calculating the size of seg_tree
        int tree_h=(int)ceil(log2(n)+1e-9);
        int tr_sz=(1 << (tree_h+1));
        for(int i=0;i<n;i++){
            scanf("%d",&h[i]);    
        }
        // allocating seg_tree
        vector<int> tree(tr_sz);
        // initializing seg_tree
        Init_Seg(h,tree,1,0,n-1);
        Search(h,tree,1,0,n-1,0,n-1);

        printf("%lld",area);
    }
    return 0;
}