#include <cstdio>
#include <algorithm>
using namespace std;

int map[500][500];
int copyd[500][500];
int n,m;
int max_v;

inline int get_sum(int type){
    int res=0;
    int cmp;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j){
        if(type==1){
            if(i>=3){
                cmp=map[i][j]+map[i-1][j]+map[i-2][j]+map[i-3][j];
                res=max(res,cmp);
            }
        }
        else if(type==2){
            if(i>=1 && j>=1){
                cmp=map[i][j]+map[i-1][j]+map[i][j-1]+map[i-1][j-1];
                res=max(res,cmp);
            }
        }
        else if(type==3){
            if(j>=1 && i>=2){
                cmp=map[i][j]+map[i][j-1]+map[i-1][j-1]+map[i-2][j-1];
                res=max(res,cmp);
            }
        }
        else if(type==4){
            if(j>=1 && i>=2){
                cmp=map[i][j]+map[i-1][j]+map[i-1][j-1]+map[i-2][j-1];
                res=max(res,cmp);
            }
        }
        else{
            if(j>=1 && j<=m-2 && i>0){
                cmp=map[i][j]+map[i-1][j]+map[i-1][j-1]+map[i-1][j+1];
                res=max(res,cmp);
            }
        }
    }

    return res;
}

inline void rotate(){
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) copyd[i][j]=map[i][j];
    swap(n,m);
    for(int i=0;i<n;++i) for(int j=0;j<m;++j){
        map[i][j]=copyd[j][n-1-i];
    }
}

inline void reverse(){
    for(int i=0;i<n;++i) for(int j=0;j<m/2;++j){
        swap(map[i][j],map[i][m-1-j]);
    }
}

inline void process(int type){
    int sum;

    if(type==1){
        sum=get_sum(type);
        rotate();
        sum=max(sum,get_sum(type));
    }
    else if(type==2){
        sum=get_sum(type);
    }
    else if(type==3){
        sum=get_sum(type);
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        
        reverse();
        
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
    }
    else if(type==4){
        sum=get_sum(type);
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        
        reverse();
        
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
    }
    else{
        sum=get_sum(type);
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
        rotate();
        sum=max(sum,get_sum(type));
    }
    
    max_v=max(max_v,sum);
}

int main(){
    max_v=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) scanf("%d",&map[i][j]);

    for(int i=1;i<=5;++i) process(i);

    printf("%d\n",max_v);
}