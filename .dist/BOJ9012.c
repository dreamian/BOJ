#include <stdio.h>
#include <string.h>

struct stack{
    int right;
    char arr[51];
}st;

void pop(){
    if(st.right!=-1) {st.right--;}
}

void push(char i){
    st.arr[++st.right]=i;
}

int empty(){
    if(st.right==-1) {return 1;}
    else return 0;
}

int main(void){
    int n;
    scanf("%d",&n);
    int ans[n];

    for(int i=0;i<n;i++){
        char seq[51];
        scanf("%s",seq);
        st.right=-1;
        int len=strlen(seq);
        for(int j=0;j<len;j++){
            if(seq[j]=='(') {push('(');}
            else if (seq[j]==')' && st.arr[st.right]=='(') {pop();}
            else {push(')'); break;}
        }

        ans[i]=empty();
    }
    for(int i=0;i<n;i++){
        if (ans[i]==1) {printf("YES\n");}
        if (ans[i]==0) {printf("NO\n");}
    }
}