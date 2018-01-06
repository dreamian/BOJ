#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *llink;
    struct node *rlink;
}node;

typedef struct deque{
    node *front;
    node *rear;
}deque;

void Push(deque *deq, int i){ 
    node *new=(node *)malloc(sizeof(node));
    new->data=i; new->rlink=NULL;

    if(deq->front==NULL && deq->rear==NULL){
        new->llink=NULL;
        deq->front=new; deq->rear=new;
    }
    else{
        deq->rear->rlink=new;
        deq->rear=new;
    }
}

deque* Init_deq(int n){
    deque *deq;
    deq=(deque *)malloc(sizeof(deque));
    deq->front=NULL;
    deq->rear=NULL;
    for(int i=1;i<=n;i++){
        Push(deq,i);
    }

    deq->rear->rlink=deq->front;
    deq->front->llink=deq->rear; 

    return deq;
}

void delete_front(deque *deq){
    node *trash=deq->front;
    deq->front=deq->front->rlink;
    deq->front->llink=deq->rear;
    deq->rear->rlink=deq->front;
    free(trash);
}

void Answer(int m,int arr[],deque *deq,int n){
    int a=0, sum=0; 
    for(int i=0;i<m;i++){
        int cnt=0;
        a=arr[i];
        for(;;){
            if(deq->front->data==a){
                break;
            }
            else{
                deq->front=deq->front->rlink;
                deq->rear=deq->rear->rlink; 
                cnt++;
            }
        }
        if (cnt<=(n-i-cnt)) {sum+=cnt;}
        else {sum+=n-i-cnt;}

        delete_front(deq);
    }
    printf("%d\n",sum);
}

int main(void){
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    int arr[51];
    deque* deq=Init_deq(n);

    for(int i=0;i<m;i++){
        getchar();
        scanf("%d",&arr[i]);
    }

    Answer(m,arr,deq,n);
}