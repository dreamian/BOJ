#include <stdio.h>
#include <malloc.h>

typedef long long ll;
ll temp=1000000000000;
typedef struct Int{
    ll h;
    ll l;
}Int;
Int BI[101][101]={0,};


void Comb(int n, int m){
    //if (m>n/2) {Comb(n,n-m); printf("%d %d\n",n,n-m);}
        for(int i=2;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0) {BI[i][j].l=1;}
                else if (j==1) {BI[i][j].l=i;}
                else {
                    BI[i][j].l=BI[i-1][j-1].l+BI[i-1][j].l;
                    BI[i][j].h=BI[i-1][j-1].h+BI[i-1][j].h;
                }
                if (BI[i][j].l/temp==1){
                    BI[i][j].l%=temp;
                    BI[i][j].h++;
                } 
            }
        }
}

int main(void){
    int n, m;
    scanf("%d %d",&n,&m);
    BI[1][0].l=1;
    BI[1][1].l=1;
    if(m>n/2){
        m=n-m;
    }
    Comb(n,m);

    int len=0;
    ll temp=BI[n][m].l;
    while(temp!=0){
        temp/=10;
        len++;
    }

    if(BI[n][m].h>=1){
        printf("%lld",BI[n][m].h);
           if(len<12){
              int a=12-len;
             while(a--){
             printf("0");
            }
    }
    }
    printf("%lld\n",BI[n][m].l);
}