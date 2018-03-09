#include <cstdio>
using namespace std;

int n;
struct N{
    char data;
    int left;
    int right;
    N () : data(), left(-1), right(-1) {}
};

N node[201];

inline bool is_digit(int root){
    if(node[root].data=='+') return false;
    else if(node[root].data=='-') return false;
    else if(node[root].data=='*') return false;
    else if(node[root].data=='/') return false;
    else return true;
}

inline bool inorder(int root){
    // leaf node의 경우
    if(node[root].left==-1) return is_digit(root);
    else{
        // leaft node가 아닌데 숫자를 가지는 경우
        if(is_digit(root)) return false;
        // 연산자를 가지는 경우
        else{
            bool left_chk=inorder(node[root].left);
            bool right_chk=inorder(node[root].right);
            if(left_chk && right_chk) return true;
            else return false;
        }
    }
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        printf("#%d ",tc);
        scanf("%d\n",&n);
        for(int i=0;i<n;++i){
            int it,ll,rr;
            char dat;
            scanf("%d",&it);
            if(it*2+1<=n){
                scanf(" %c %d %d\n",&dat,&ll,&rr);
                node[it].data=dat;
                node[it].left=ll;
                node[it].right=rr;
            }
            else{
                scanf(" %c\n",&dat);
                node[it].data=dat;
                node[it].left=-1;
                node[it].right=-1;
            }
        }
        bool flag=inorder(1);
        flag ? printf("1\n") : printf("0\n");
    }
    return 0;
}