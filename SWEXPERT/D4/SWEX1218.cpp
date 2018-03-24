#include <cstdio> 
#include <stack>
using namespace std;
#define open_condition tar=='(' || tar=='<' || tar=='{' || tar=='['

char buf[300];

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        stack<char> proc;
        int len;
        scanf("%d",&len);
        
        bool possible=true;
        scanf("%s",buf);
        for(int i=0;i<len;++i){
            char tar=buf[i];
            if(open_condition) proc.push(tar);
            else{
                if(proc.empty()) possible=false;
                else if(tar==')'){
                    if(proc.top()=='(') proc.pop();
                    else possible=false;
                }
                else if(tar==']'){
                    if(proc.top()=='[') proc.pop();
                    else possible=false;
                }
                else if(tar=='}'){
                    if(proc.top()=='{') proc.pop();
                    else possible=false;
                }
                else{
                    if(proc.top()=='<') proc.pop();
                    else possible=false;
                }
            }
            if(!possible) break;
        }

        if(!proc.empty()) possible=false;

        printf("#%d ",tc);
        possible ? printf("1\n") : printf("0\n");
    }
    return 0;
}