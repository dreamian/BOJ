#include <cstdio>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;

// null node : 0, core : 1 wire : 2
int arr[13][13]={0,};
bool flag;
int n;
int min(int i,int j,int k,int l){
    i=i<j?i:j;
    i=i<k?i:k;
    i=i<l?i:l;
    return i;
}
int ups(vector< pair<int, int> > v,int idx,int sz,int board[13][13]);
int downs(vector< pair<int, int> > v,int idx,int sz,int board[13][13]);
int lefts(vector< pair<int, int> > v,int idx,int sz,int board[13][13]);
int rights(vector< pair<int, int> > v,int idx,int sz,int board[13][13]);

int DFS(vector< pair<int, int> > v,int idx,int sz,int carr[13][13]){
    if(idx==sz){
        return 0;
    }
    int up=n*n, down=n*n, left=n*n, right=n*n;
    
    // up
    up=ups(v,idx,sz,carr);
    // down
    down=downs(v,idx,sz,carr);
    // left
    left=lefts(v,idx,sz,carr);
    // right
    right=rights(v,idx,sz,carr);
    
    return min(up,down,left,right);
}

int ups(vector< pair<int, int> > v,int idx,int sz,int board[13][13]){
    flag=true;
    for(int i=0;i<v[idx].first;i++){
        if(board[i][v[idx].second]==1 || board[i][v[idx].second]==2){
            flag=false; break;
        }
    }
    if(flag){
         for(int i=0;i<v[idx].first;i++) board[i][v[idx].second]=2;
         int up=v[idx].first+DFS(v,idx+1,sz,board);
         for(int i=0;i<v[idx].first;i++) board[i][v[idx].second]=0;
         return up;
    }
    else return n*n;
}

int downs(vector< pair<int, int> > v,int idx,int sz,int board[13][13]){
    flag=true;
    for(int i=n-1;i>v[idx].first;i--){
        if(board[i][v[idx].second]==1 || board[i][v[idx].second]==2){
            flag=false; break;
        }
    }
    if(flag){
         for(int i=n-1;i>v[idx].first;i--) board[i][v[idx].second]=2;
         int down=(n-v[idx].first-1)+DFS(v,idx+1,sz,board);
         for(int i=n-1;i>v[idx].first;i--) board[i][v[idx].second]=0;
         return down;
    }
    else return n*n;
}

int lefts(vector< pair<int, int> > v,int idx,int sz,int board[13][13]){
    flag=true;
    for(int j=0;j<v[idx].second;j++){
        if(board[v[idx].first][j]==1 || board[v[idx].first][j]==2){
            flag=false; break;
        }
    }
    if(flag){
         for(int j=0;j<v[idx].second;j++) board[v[idx].first][j]=2;
         int left=v[idx].second+DFS(v,idx+1,sz,board);
         for(int j=0;j<v[idx].second;j++) board[v[idx].first][j]=0;
         return left;
    }
    else return n*n;
}

int rights(vector< pair<int, int> > v,int idx,int sz,int board[13][13]){
    flag=true;
    for(int j=n-1;j>v[idx].second;j--){
        if(board[v[idx].first][j]==1 || board[v[idx].first][j]==2){
            flag=false; break;
        }
    }
    if(flag){
         for(int j=n-1;j>v[idx].second;j--) board[v[idx].first][j]=2;
         int right=(n-v[idx].second-1)+DFS(v,idx+1,sz,board);
         for(int j=n-1;j>v[idx].second;j--) board[v[idx].first][j]=0;
         return right;
         
    }
    else return n*n;
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
        for(int te=1;te<=t;te++){

        memset(arr,0,sizeof(arr));
        int alr=0; // initializing
        scanf("%d",&n);
        vector< pair<int, int> > v;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
                if(i==0 || i==n-1 || j==0 || j==n-1){
                    if(arr[i][j]==1) alr+=1;
                }
                else if(arr[i][j]==1) v.push_back(pair<int, int>(i,j));
            }
        }

        for(int i=0;i<v.size();i++){
            int cnt=4;
            // left
            for(int dir=0;dir<v[i].second;dir++){
                if(arr[v[i].first][dir]==1){
                    cnt--; break;
                }
            }
            // right
            for(int dir=n-1;dir>v[i].second;dir--){
                if(arr[v[i].first][dir]==1){
                    cnt--; break;
                }
            }
            // up
            for(int dir=0;dir<v[i].first;dir++){
                if(arr[dir][v[i].second]==1){
                    cnt--; break;
                }
            }
            // down
            for(int dir=n-1;dir>v[i].first;dir--){
                if(arr[dir][v[i].second]==1){
                    cnt--; break;
                }
            }
            if(cnt==0) { v.erase(v.begin()+i); i--;}
        }


        if(alr>=4*(n-1)) {printf("#%d 0\n",te);}
        else{
        printf("#%d %d\n",te,DFS(v,0,v.size(),arr));
        }
    }
}