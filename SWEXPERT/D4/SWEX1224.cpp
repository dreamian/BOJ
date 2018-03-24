#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int len;
stack<char> oper;
queue<char> postfix;
stack<ll> postfix_deoper;

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        scanf("%d\n",&len);
        for(int i=0;i<len;++i){
            char a;
            scanf("%c",&a);
            if('0'<=a && a<='9') postfix.push(a);
            else{
                if(oper.empty()) oper.push(a);
                else if(a=='(') oper.push(a);
                else if(a==')'){
                    while(1){
                        char a=oper.top();
                        oper.pop();
                        if(a=='(') break;
                        postfix.push(a);
                    }
                }
                else if(a=='+' || a=='-'){
                    while(1){
                        if(oper.empty()){
                            oper.push(a);
                            break;
                        }
                        
                        char it=oper.top();
                        if(it=='*' || it=='/'){
                            postfix.push(it);
                            oper.pop();
                        }
                        else{
                            oper.push(a);
                            break;
                        }
                    }
                }
                else oper.push(a);
            }
        }
        getchar();
        while(!oper.empty()){
            postfix.push(oper.top());
            oper.pop();
        }
        while(!postfix.empty()){
            char tar=postfix.front();
            postfix.pop();

            if('0'<=tar && tar<='9') postfix_deoper.push(tar-'0');
            else{
                ll a=postfix_deoper.top();
                postfix_deoper.pop();
                ll b=postfix_deoper.top();
                postfix_deoper.pop(); 

                if(tar=='+') postfix_deoper.push(a+b);
                else if(tar=='-') postfix_deoper.push(a-b);
                else if(tar=='*') postfix_deoper.push(a*b);
                else if(tar=='/') postfix_deoper.push(a/b);   
            }
        }
        ll ans=postfix_deoper.top();
        postfix_deoper.pop();
        printf("#%d %lld\n",tc,ans);
    }
    return 0;
}