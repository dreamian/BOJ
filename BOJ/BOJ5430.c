#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *llink;
    struct node *rlink;
}node;

typedef struct deque{
    node *head;
    node *tail; 
}deque;

deque* Init(void){
    deque *deq;
    deq=(deque *)malloc(sizeof(deque));
    deq->head=NULL;
    deq->tail=NULL;

    return deq;
}

int Empty(deque* deq){
    if(deq->head==NULL&&deq->tail==NULL) {return 1;}
    else return 0;
}

void Push(deque* deq,int a){ //tail에 넣는 경우만 고려
    node *new;
    new=(node *)malloc(sizeof(node));
    new->rlink=NULL; new->data=a;
    if (Empty(deq)==1){
        deq->head=new; deq->tail=new;
        deq->head->rlink=deq->tail;
    }
    else{
        deq->tail->rlink=new;
        new->llink=deq->tail;
        deq->tail=new;
    }
}
int size(deque *deq){ // 단일 큐인 func에 대해서만 고려할 것
    if (deq->head==NULL) {return 0;}
    node *temp=deq->head; int cnt=0;
    if(temp->rlink==temp) {return ++cnt;}
    while(temp){
        temp=temp->rlink; cnt++;
    }
    return cnt;
}

void Pop_head(deque *deq){
    if(deq->head==deq->tail && deq->head!=NULL) {deque *temp=deq; free(temp);
                                                    deq=Init();}
    else{  
    node *trash=deq->head;
    deq->head=deq->head->rlink;
    deq->head->llink=deq->tail;
    deq->tail->rlink=deq->head;
    free(trash);
    }
}

void Pop_tail(deque *deq){
    if(deq->head==deq->tail) {deq=Init();}
    else{  
    node *trash=deq->tail;
    deq->tail=deq->tail->llink;
    deq->tail->rlink=deq->head;
    deq->head->llink=deq->tail;
    free(trash);
    }
}

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	scanf("%d\n", &T);
	for(test_case = 0; test_case < T; test_case++)
	{   int n;
        deque* num=Init();
        deque* func=Init();
        char* f=(char *)malloc(sizeof(char)*100001);
        scanf("%s\n%d\n",f,&n);
        int len=strlen(f);
        while(n--){
            int a;
            getchar();
            scanf("%d",&a);
            Push(num,a);
        }
        if(len>1){
            for(int i=0;i<len;i++){
                if(f[i]=='R'&&f[i+1]=='R'){i++;}
                else {Push(func,f[i]);}             
            } // func 완성 (단일 큐 구현), 중복되는 함수의 경우 단일 출력고려했음.
        }
        else{
            int a=f[0];
            Push(func,a);
        }
        int size_func=size(func);
        if(Empty(num)==0){num->tail->rlink=num->head; num->head->llink=num->tail;} // 수 배열의 원형 큐 완성
        // head가 6시 방향에 있을 때 반시계로 회전하는 것을 먼저 고려.
        if (size_func==0 && num->head==NULL) {printf("[]\n");}
    else{
        int idx=1; // 1은 반시계 방향, -1은 시계 방향 회전.
        int err=0;
        while(size_func--){
            if(func->head->data=='D'){ if(num->head==NULL||num->tail==NULL) { err+=1;}
                                       else if(idx==1) Pop_head(num); 
                                       else {Pop_tail(num);} 
                                    }
            if(func->head->data=='R'){ idx*=-1;}
            Pop_head(func); // 원형 큐로 계산.
        }
        if(num->head==NULL && err==0) {printf("[]\n");}
        else if (err!=0) {printf("error\n");}
        if(err==0 && num->head!=NULL){
        printf("[");
        if(idx==1){
            node *temp=num->head;
            while(temp!=num->tail){
                printf("%d,",temp->data);
                temp=temp->rlink;
            }
            printf("%d]\n",num->tail->data); 
        }
        else{
            node *temp=num->tail;
            while(temp!=num->head){
                printf("%d,",temp->data);
                temp=temp->llink;
                }
            printf("%d]\n",num->head->data);     
            } 
        }
        
    }
        free(num);
        free(func);
        free(f);
        if(test_case-T!=-1) while (getchar() != '\n');
        else return 0;
    }    


	return 0;
    
}
