#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

ll area;

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

// search the minimum height in range form i to j
int Search(vector<int> &h, vector<int> &tree, int node, int start, int end,int i, int j){
    if(j<start || end<i){
        return -1;
    }
    else if(i<=start && end<=j){
        return tree[node];
    }
    int mid=(start+end) >> 1;
    int m1=Search(h,tree,2*node,start,mid,i,j);
    int m2=Search(h,tree,2*node+1,mid+1,end,i,j);
    if(m1==-1){
        return m2;
    }
    if(m2==-1){
        return m1;
    }
    else{
        return h[m1]<h[m2]?m1:m2;
    }
}

// return the calculated area in the range of left and right at lowest height index
void Calc(vector<int> &h, vector<int> &tree, int start, int end){
    int n=h.size();
    int m=Search(h,tree,1,0,n-1,start,end);
    // int형 간의 계산에서 overflow가 발생할 수 있으므로 long long형으로 변환
    area=area>h[m]*(long long)(end-start+1)?area:h[m]*(long long)(end-start+1);
    if(start<=m-1){
        Calc(h,tree,start,m-1);
    }
    if(m+1<=end){
        Calc(h,tree,m+1,end);
    }
}   

int main(void){
    int n;
    while(1){
        area=-1;
        scanf("%d",&n);
        if(n==0) break;
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
        Calc(h,tree,0,n-1);

        printf("%lld\n",area);
    }
    return 0;
}