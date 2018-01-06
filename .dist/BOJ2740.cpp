#include <cstdio>

// n X m :: m X o -> n X o
int n,m;
int arr1[100][100];
int o;
int arr2[100][100];

void mul(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            int a=0;
            for(int k=0;k<m;k++){
                a+=arr1[i][k]*arr2[k][j];
            }
            printf("%d ",a);
        }
        printf("\n");
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    scanf("%*d %d",&o);
    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    mul();
}