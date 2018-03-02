#include <cstdio>
using namespace std;

// 행, 열 성분 검사
bool rc[2][9][9];

// 각 3x3 성분 검사
bool matrix[9][9];

// map
int board[9][9];

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        bool pos=true;

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                scanf("%d",&board[i][j]);
                --board[i][j];
            }
        }

        for(int i=0;i<9;++i)for(int j=0;j<9;++j){
            // rc 검사
            /// r
            if(rc[0][i][board[i][j]]){
                pos=false;
                break;
            }
            else rc[0][i][board[i][j]]=true;
            /// c
            if(rc[1][j][board[i][j]]){
                pos=false;
                break;
            }
            else rc[1][j][board[i][j]]=true;

            // matrix 검사
            int type=0;
            if(i/3==1) type+=1;
            else if(i/3==2) type+=2;
            
            if(j/3==1) type+=3;
            else if(j/3==2) type+=6;
            
            if(matrix[type][board[i][j]]){
                pos=false;
                break;
            }
            else matrix[type][board[i][j]]=true;
            
        }


        pos ? printf("1\n") : printf("0\n");
        
        // Init
        for(int i=0;i<2;++i)for(int j=0;j<9;++j)for(int k=0;k<9;++k) rc[i][j][k]=false;
        for(int i=0;i<9;++i)for(int j=0;j<9;++j) matrix[i][j]=false;   
    }
    return 0;
}