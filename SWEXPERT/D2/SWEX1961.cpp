#include <cstdio>
using namespace std;

int n;
int board[7][7];

inline void process_1(int i){
    for(int j=n-1;j>=0;--j) printf("%d",board[j][i]);
}

inline void process_2(int i){
    i=n-i-1;
    for(int j=n-1;j>=0;--j) printf("%d",board[i][j]); 
}

inline void process_3(int i){
    i=n-i-1;
    for(int j=0;j<n;++j) printf("%d",board[j][i]);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d\n",tc);
        scanf("%d",&n);
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) scanf("%d",&board[i][j]);
        for(int i=0;i<n;++i){
            process_1(i);
            printf(" ");
            process_2(i);
            printf(" ");
            process_3(i);
            printf("\n");
        }
    }
    return 0;
}