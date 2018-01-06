#include <stdio.h>
#include <string.h>

struct stack{
    int right;
    char arr[31];
}st;

void pop(void){
    st.right--;
}

void push(int i){
    st.arr[++st.right]=i;
}

int empty(){
    if(st.right==-1) {return 1;}
    else return 0;
}

int main(void){
    char seq[31];
    int ans=1, sum=0;
    scanf("%s",seq);
        st.right=-1;
        int len=strlen(seq);
        for(int j=0;j<len;j++){
            if(seq[j]=='(') {push('('); ans*=2;}
            else if(seq[j]=='[') {push('['); ans*=3;}
            else if (seq[j]==')' && st.arr[st.right]=='(') 
                {pop(); if(seq[j-1]=='(') {sum+=ans;}
                    if(st.right!=-1) {ans/=2;} else {ans=1;}} 
            else if (seq[j]==']' && st.arr[st.right]=='[') 
                {pop(); if(seq[j-1]=='[') {sum+=ans;}
                    if(st.right!=-1) {ans/=3;} else {ans=1;}}
            else {push('a'); break;}
        }

        ans=empty();
        if (ans==1) {printf("%d\n",sum);}
        else {printf("0\n");}
    
}