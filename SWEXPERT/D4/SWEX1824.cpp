#include <cstdio>
#include <utility>
using namespace std;
#define mp make_pair
#define pii pair<int,int>

int r,c;
char map[20][20];
bool chk[20][20][16][4];
const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

pii mov_query(int i, int j, int dir){
    pii res=mp(i+mov[dir][0],j+mov[dir][1]);
    if(res.first<0) res.first+=r;
    else if(res.first>=r) res.first-=r;

    if(res.second<0) res.second+=c;
    else if(res.second>=c) res.second-=c;

    return res;
}

inline bool DFS(int i, int j, int mem, int dir){
    // 종결 조건
    if(chk[i][j][mem][dir]) return false;
    
    chk[i][j][mem][dir]=true;
    char ord=map[i][j];
    pii next;

    if(ord=='?'){
        for(int idx=0;idx<4;++idx){
            next=mov_query(i,j,idx);
            bool a=DFS(next.first,next.second,mem,idx);
            if(a) return true;
        }
        return false;
    }
    else{
        if(ord=='<'){
            dir=2;
        }
        else if(ord=='>'){
            dir=3;
        }
        else if(ord=='^'){
            dir=0;
        }
        else if(ord=='v'){
            dir=1;
        }
        else if(ord=='_'){
            if(mem==0) dir=3;
            else dir=2;
        }
        else if(ord=='|'){
            if(mem==0) dir=1;
            else dir=0;
        }
        else if(ord=='@'){
            return true;
        }
        else if(ord>='0' && ord<='9'){
            mem=ord-'0';
        }
        else if(ord=='+'){
            ++mem;
            if(mem==16) mem=0;
        }
        else if(ord=='-'){
            --mem;
            if(mem==-1) mem=15;
        }
        next=mov_query(i,j,dir);
        return DFS(next.first,next.second,mem,dir);
        
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d\n",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        bool flag=false;
        scanf("%d %d\n",&r,&c);
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                scanf("%c",&map[i][j]);
                if(map[i][j]=='@') flag=true;
                for(int k=0;k<16;++k){
                    for(int l=0;l<4;++l){
                        chk[i][j][k][l]=false;
                    }
                }
            }
            scanf("\n");
        }
        if(!flag){
            printf("NO\n");
            continue;
        } 
        bool ans=DFS(0,0,0,3);
        ans ? printf("YES\n") : printf("NO\n") ;
    }
    return 0;
}