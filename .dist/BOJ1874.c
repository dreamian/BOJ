#include <stdio.h>

struct stack{
    int arr[100001];
    int top;
}st;
void pop(void){
    --st.top;
}
void push(int arg){
    st.arr[++st.top]=arg;
}

int main(void){
    int ans[200002];
    int n, num=1;
    int ans_c=0;
    st.top=-1;
    scanf("%d",&n);
    int seq[n];
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    int idx=0;
    while(idx!=n){
        int diff=seq[idx]-num, cnt=diff+1;
        if(diff==-1 || st.arr[st.top]==seq[idx]) {pop(); idx++; ans[ans_c++]='-';}
        else if (diff>=0) {while((cnt)--){push(num++); ans[ans_c++]='+';}}
        else  {ans_c=-1; break;}
    }
    if (ans_c==-1) printf("NO\n");
    else { for(int j=0;j<ans_c;j++){printf("%c\n",ans[j]); }}

}