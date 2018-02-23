#include <cstdio>
#include <vector>
using namespace std;

int ans;
int n,m;
int board[20][20];

inline int opex(int k){
    return k*k+(k-1)*(k-1);
}

inline bool is_range(int i){
    if(i<0 || i>n-1) return false;
    else return true;
}

inline void process(const int i, const int j, int k, const int max_k){
    if(k>max_k) return;
    int house=0;

    // 마름모 위+아래 부분
    for(int row=k-1;row>=1;--row){
        bool fl_up=is_range(i-row);
        bool fl_down=is_range(i+row);

        for(int col=k-(row+1);col>=0;--col){
            bool fl_left=is_range(j-col);
            bool fl_right=is_range(j+col);
            if(fl_up){
                if(col==0){
                    if(board[i-row][j]==1) ++house;
                }
                else{
                    if(fl_left){
                        if(board[i-row][j-col]==1) ++house;
                    }
                    if(fl_right){
                        if(board[i-row][j+col]==1) ++house;
                    }
                }
            }
            if(fl_down){
                if(col==0){
                    if(board[i+row][j]==1) ++house;
                    continue;
                }
                else{
                    if(fl_left){
                        if(board[i+row][j-col]==1) ++house;
                    }
                    if(fl_right){
                        if(board[i+row][j+col]==1) ++house;
                    }
                }
            }
        }
    }

    // 마름모 중앙
    for(int col=j-(k-1);col<j+k;++col){
        if(board[i][col]==1 && is_range(col)) ++house;
    }

    int profit=m*house-opex(k);
    if(profit>=0) ans=max(ans,house);

    process(i,j,k+1,max_k);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int tc=1;tc<=t;++tc){
        scanf("%d%d",&n,&m);
        // Init
        ans=0;
        int house=0;

        // board
        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            scanf("%d",&board[i][j]);
            if(board[i][j]==1) ++house;
        }

        // Init
        const int profit=m*house;
        int max_k=1;
        int net=profit-opex(max_k);
        while(net>0){
            net=profit-opex(++max_k);
        }

        // Process
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) process(i,j,1,max_k);

        printf("#%d %d\n",tc,ans);
    }
}