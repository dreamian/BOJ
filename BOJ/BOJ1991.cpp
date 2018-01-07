#include <cstdio>
#include <malloc.h>
using namespace std;

struct node{
    char data;
    struct node* llink;
    struct node* rlink;
};

// alphabet node set
node* p[26];

// tree 초기화
node* Init_tree(){
    node* T=(node *)malloc(sizeof(node));
    T->llink=NULL;
    T->rlink=NULL;
    T->data='A';
    p[0]=T;

    return T;
}

// 주어진 입력값을 토대로 tree 구현
void Make_tree(char a, char b, char c,node* T){
    node* L=(node *)malloc(sizeof(node));
    node* R=(node *)malloc(sizeof(node));
    
    if(a=='A'){
        if(b!='.'){
            T->llink=L;
            T->llink->data=b;
            p[b-48]=T->llink; 
        }                  
        else{
            free(L);
        }
        if(c!='.'){
            T->rlink=R;
            T->rlink->data=c;
            p[c-48]=T->rlink;
        }
        else{
            free(R);
        }
    }
    else{
        node* parent=p[a-48];
        if(b!='.'){
            parent->llink=L;
            parent->llink->data=b;
            p[b-48]=parent->llink;
        }
        else{
            free(L);
        }
        if(c!='.'){
            parent->rlink=R;
            parent->rlink->data=c;
            p[c-48]=parent->rlink;
        }
        else{
            free(R);
        }
    }
}

// 전위 순회
void Pre_order(node* root){
    printf("%c",root->data);
    if(root->llink!=NULL) Pre_order(root->llink);
    if(root->rlink!=NULL) Pre_order(root->rlink);
}

// 중위 순회
void In_order(node* root){
    if(root->llink!=NULL) In_order(root->llink);
    printf("%c",root->data);
    if(root->rlink!=NULL) In_order(root->rlink);
}

// 후위 순회
void Post_order(node* root){
    if(root->llink!=NULL) Post_order(root->llink);
    if(root->rlink!=NULL) Post_order(root->rlink);
    printf("%c",root->data);
}

int main(){
    int n;
    node* T=Init_tree();
    scanf("%d",&n);
    while(n--){
        char a,b,c;
        scanf(" %c %c %c",&a,&b,&c);
        Make_tree(a,b,c,T);
    }
    Pre_order(T);
    printf("\n");
    In_order(T);
    printf("\n");
    Post_order(T);
    printf("\n");
}