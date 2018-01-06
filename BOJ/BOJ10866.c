#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *llink;
    struct node *rlink;
}node;

typedef struct deque{
    node *front, *rear;
}deque;

deque* init_deq(void){
    deque *deq;
    deq=(deque *)malloc(sizeof(deque));
    deq->front=NULL;
    deq->rear=NULL;
    return deq;
}

void push_front(deque *deq, int item){
    node *new=(node *)malloc(sizeof(node));
    new->data=item;
    if(deq->front==NULL){
        deq->front=new;
        deq->rear=new;
        new->rlink=NULL;
        new->llink=NULL;
    }
    else{
        deq->front->llink=new;
        new->rlink=deq->front;
        new->llink=NULL;
        deq->front=new;
    }
}

void push_back(deque *deq, int item){
    node *new=(node *)malloc(sizeof(node));
    new->data=item;
    if(deq->rear==NULL){
        deq->rear=new;
        deq->front=new;
        new->rlink=NULL;
        new->llink=NULL;
    }
    else{
        deq->rear->rlink=new;
        new->llink=deq->rear;
        new->rlink=NULL;
        deq->rear=new;
    }
}

void pop_front(deque *deq){
    if(deq->front==NULL){
        printf("-1\n");
    }
    else{
        node *trash=deq->front;
        printf("%d\n",deq->front->data);
        if(deq->rear!=deq->front){
            deq->front=deq->front->rlink;
            deq->front->llink=NULL;
        }
        else{
            deq->front=NULL; deq->rear=NULL;
        }
        free(trash);
    }
}

void pop_back(deque *deq){
    if(deq->rear==NULL){
        printf("-1\n");
    }
    else{
        node *trash=deq->rear;
        printf("%d\n",deq->rear->data);
        if(deq->front!=deq->rear){
            deq->rear=deq->rear->llink;
            deq->rear->rlink=NULL;
        }
        else{
            deq->rear=NULL; deq->front=NULL;
        }
        free(trash);
    }
}

void size(deque *deq){
    node *temp=deq->front;
    int cnt=0;
    while(temp){
        temp=temp->rlink;
        cnt++;
    }
    printf("%d\n",cnt);
}

void empty(deque * deq){
    if(deq->front==NULL) {printf("1\n");}
    else printf("0\n");
}

void front_(deque *deq){
    if(deq->front==NULL){
        printf("-1\n");
    }
    else{
        printf("%d\n",deq->front->data);
    }
}

void back_(deque *deq){
    if(deq->rear==NULL){
        printf("-1\n");
    }
    else{
        printf("%d\n",deq->rear->data);
    }
}

int main(void){
    int n;
    int a=0; 
    deque *deq=init_deq();
    scanf("%d",&n);
    while(n--){
        char ch[11];
        scanf("%s",ch);
        if (ch[0]=='p'){
            if (ch[1]=='u' && ch[5]=='f') { scanf("%d",&a);
                                            push_front(deq,a);}
            if (ch[1]=='u' && ch[5]=='b') { scanf("%d",&a);
                                            push_back(deq,a);}
            if (ch[1]=='o' && ch[4]=='f') {pop_front(deq);}
            if (ch[1]=='o' && ch[4]=='b') {pop_back(deq);}
        }
        else if (ch[0]=='s'){size(deq);}
        else if (ch[0]=='e'){empty(deq);}
        else if (ch[0]=='f'){front_(deq);}
        else if (ch[0]=='b'){back_(deq);}
        getchar();
    }
}