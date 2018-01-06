#include <stdio.h>

struct stack{
    int top;
    int arr[10001];
};

int main(void){
    struct stack st;
    st.top=-1;
    char ch[6];

    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",ch);
        if(ch[0]=='s') {printf("%d\n",st.top+1);}
        if(ch[0]=='e') {if(st.top==-1) printf("1\n");
                        else printf("0\n");}
        if(ch[0]=='t') {if(st.top==-1) printf("-1\n");
                        else printf("%d\n",st.arr[st.top]);}
        if(ch[0]=='p'&&ch[1]=='u') {scanf("%d",&st.arr[++(st.top)]);}
        if(ch[0]=='p'&&ch[1]=='o') {if(st.top!=-1) {printf("%d\n",st.arr[st.top]); st.top--;}
                                    else printf("-1\n");}
    }

}