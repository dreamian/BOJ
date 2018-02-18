#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_LEN 300000
#define ALPH_SIZE 123

char A[MAX_LEN+1];
int N,pos[MAX_LEN],rank_[MAX_LEN];
int cont[MAX_LEN],next_[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
    N = strlen(A);
    
    memset(cont,0,sizeof(cont));
    
    for(int i = 0;i<N;++i) ++cont[A[i]];
    for(int i = 1;i<ALPH_SIZE;++i) cont[i] += cont[i-1];
    for(int i = 0;i<N;++i) pos[--cont[A[i]]] = i;
    
    for(int i = 0;i<N;++i){
        bh[i] = (i==0 || A[pos[i]]!=A[pos[i-1]]);
        b2h[i] = false;
    }
    
    for(int H = 1;H<N;H <<= 1){
        int buckets = 0;
        
        for(int i = 0,j;i<N;i = j){
            j = i+1;
            
            while(j<N && !bh[j]) ++j;
            next_[i] = j;
            ++buckets;
        }
        
        if(buckets==N) break;
        
        for(int i = 0;i<N;i = next_[i]){
            cont[i] = 0;
            for(int j = i;j<next_[i];++j)
                rank_[pos[j]] = i;
        }
        
        ++cont[rank_[N-H]];
        b2h[rank_[N-H]] = true;
        
        for(int i = 0;i<N;i = next_[i]){
            for(int j = i;j<next_[i];++j){
                int s = pos[j]-H;
        
                if(s>=0){
                    int head = rank_[s];
                    rank_[s] = head+cont[head];
                    ++cont[head];
                    b2h[rank_[s]] = true;
                }
            }
            
            for(int j = i;j<next_[i];++j){
                int s = pos[j]-H;
                
                if(s>=0 && b2h[rank_[s]]){
                    for(int k = rank_[s]+1;!bh[k] && b2h[k];++k)
                        b2h[k] = false;
                }
            }
        }
        
        for(int i = 0;i<N;++i){
            pos[rank_[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    
    for(int i = 0;i<N;++i) rank_[pos[i]] = i;
}

char s[MAX_LEN];
int lens;

pair<int,int> search(){
    int l = 0,r = N - 1;
    
    for(int i = 0;i < lens;++i){
        int lo = l,hi = r,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if(A[ pos[mi] + i ] < s[i]) lo = mi + 1;
            else hi = mi;
        }
        
        if(A[ pos[lo] + i ] != s[i]) return make_pair(-1,-1);
        l = lo;
        
        lo = l; hi = r;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(A[ pos[mi] + i ] > s[i]) hi = mi - 1;
            else lo = mi;
        }
        
        r = lo;
    }
    
    return make_pair(l,r);
}

struct node{
    int l,r,len;
    
    node(){}
    node(int _l, int _r, int _len):
        l(_l),r(_r),len(_len){}
    
    bool operator < (node X)const{
        if(l != X.l) return l < X.l;
        return r < X.r;
    }
};

int main(){
    scanf("%d %s",&N,A);
    build_suffix_array();
    
    int M;
    
    scanf("%d",&M);
    
    vector<node> v;
    
    for(int i = 0;i < M;++i){
        scanf("%s",s);
        lens = strlen(s);
        
        pair<int,int> p = search();
        
        if(p.first != -1)
            v.push_back(node(p.first,p.second,lens));
    }
    
    sort(v.begin(),v.end());
    int nv = v.size();
    
    vector< pair<int, int> > v2;
    priority_queue< pair<int, int> > Q;
    
    for(int i = 0,j = 0;i < N;++i){
        while(!Q.empty()){
            pair<int, int> p = Q.top();
            
            if(p.second < i) Q.pop();
            else break;
        }
        
        while(j < nv && v[j].l == i){
            Q.push(make_pair(v[j].len,v[j].r));
            ++j;
        }
        
        if(!Q.empty()) v2.push_back(make_pair(pos[i],pos[i] + Q.top().first - 1));
    }
    
    sort(v2.begin(),v2.end());
    nv = v2.size();
    
    int ans = 0;
    
    for(int i = 0,pos = 0;i < N;){
        if(pos == nv || v2[pos].first != i){
            ++ans;
            ++i;
        }else{
            int e = v2[pos++].second;
            
            while(pos < nv && v2[pos].first <= e + 1){
                e = max(e,v2[pos].second);
                ++pos;
            }
            
            i = e + 1;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}