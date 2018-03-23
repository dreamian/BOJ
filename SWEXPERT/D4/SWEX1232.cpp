#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[10];

struct N{
    double val;
    char oper;
    int left;
    int right;
}node[1001];

inline bool is_oper(char oper){
    if(oper=='-') return true;
    else if(oper=='+') return true;
    else if(oper=='*') return true;
    else if(oper=='/') return true;
    else return false;
}

inline double get_val(int root){
    char oper=node[root].oper;

    if(oper=='=') return node[root].val;
    else{
        double left_son=get_val(node[root].left);
        double right_son=get_val(node[root].right);
        if(oper=='-') return left_son-right_son;
        else if(oper=='+') return left_son+right_son;
        else if(oper=='*') return left_son*right_son;
        else return left_son/right_son;
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        printf("#%d ",tc);
        int ord;
        scanf("%d\n",&ord);
        int n;
        while(ord--){
            scanf("%d",&n);
            scanf("%s",buf);
            if(is_oper(buf[0])){
                node[n].oper=buf[0];
                scanf("%d%d",&node[n].left,&node[n].right);
            }
            else{
                node[n].oper='=';
                node[n].left=-1;
                node[n].right=-1;

                int val=0;
                int len=strlen(buf);
                for(int i=0;i<len;++i){
                    val+=(buf[i]-'0')*pow(10,len-i-1);
                }
                node[n].val=val;
            }
        }
        printf("%d\n",(int)get_val(1));
    }
    return 0;
}