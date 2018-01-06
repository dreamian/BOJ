#include <stdio.h>

struct queue{
    int front;
    int rear;
    int arr[10001];
}que;

void push(int i){
    que.arr[++que.rear]=i;
    if(que.front==-1) {que.front++;}
}

void pop(void){
    if(que.front<=que.rear){
    printf("%d\n",que.arr[que.front++]);
    }
    else printf("-1\n");
}

void size(void){
    if(que.front!=-1) printf("%d\n",(que.rear-que.front)+1);
    else {printf("0\n");}
}

void empty(void){
    if(que.rear<que.front||que.front==-1) {printf("1\n");}
    else {printf("0\n");}
}
void front(void){
    if(que.rear<que.front) {printf("-1\n");}
    else printf("%d\n",que.arr[que.front]);
}
void back(void){
    if(que.rear<que.front) {printf("-1\n");}
    else printf("%d\n",que.arr[que.rear]);
}

int main(void){
    que.front=-1;
    que.rear=-1;

    int i;
    char ch[6];

    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",ch);
        if(ch[0]=='s') {size();}
        if(ch[0]=='e') {empty();}
        if(ch[0]=='f') {front();}
        if(ch[0]=='b') {back();}
        if(ch[0]=='p'&&ch[1]=='u') {scanf("%d",&i); push(i);}
        if(ch[0]=='p'&&ch[1]=='o') {pop();}
    }

}