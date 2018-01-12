#include <bits/stdc++.h>
using namespace std;
#define MAX 2187

char board[MAX][MAX];

void fractal(int x, int y, int n){
    for(int i=x+n/3;i<x+2*n/3;i++){
        for(int j=y+n/3;j<y+2*n/3;j++){
            board[i][j]=' ';
        }
    }
    if(n>3){
        fractal(x,y,n/3);
        fractal(x,y+n/3,n/3);
        fractal(x,y+2*n/3,n/3);
        fractal(x+n/3,y,n/3);
        fractal(x+n/3,y+2*n/3,n/3);
        fractal(x+2*n/3,y,n/3);
        fractal(x+2*n/3,y+n/3,n/3);
        fractal(x+2*n/3,y+2*n/3,n/3);
    }
}

void Init(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='*';
        }
    }
}

int main(){
    int N;
    scanf("%d",&N);
    Init(N);
    fractal(0,0,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}