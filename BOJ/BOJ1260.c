#include <stdio.h>

int a[1001][1001];
int DFSvisit[1001];
int BFSvisit[1001];
int que[1001];
int N=0;

void DFSsearch(int v){
    DFSvisit[v]=1;
    printf("%d ",v);
    for(int i=1;i<=N;i++){
        if(DFSvisit[i]!=1 && a[i][v]==1){
            DFSsearch(i);
        }
    }
    return;
}

void BFSsearch(int v){
    int front=0, rear=0;
    BFSvisit[v]=1;
    printf("%d ",v);
    que[0]=v; rear++;

    while(front<rear){
        v=que[front]; front++;
        for(int i=1;i<=N;i++){
            if(BFSvisit[i]==0 && a[i][v]==1){
                printf("%d ",i);
                que[rear]=i; rear++;
                BFSvisit[i]=1;
            }
        }
    }

    return;
}

int main(void){
    int M,V;
    scanf("%d %d %d",&N,&M,&V);

    while(M--){
        int i,j;
        scanf("%d %d",&i,&j);
        a[i][j]=1; a[j][i]=1;
    }

    DFSsearch(V);
    printf("\n");
    BFSsearch(V);
    printf("\n");
}