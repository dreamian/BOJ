#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int p,q;
        scanf("%d %d",&p,&q);
        printf("#%d ",tc);

        // 기약 분수 형태로 바꾸기
        int comm=gcd(p,q);
        p/=comm; q/=comm; 
       
        // 정수부 출력
        int n=p/q;
        printf("%d",n);
        p-=n*q;
        if(p==0){
            printf("\n");
            continue;
        } 
        else printf(".");

        // 소수부
        vector<int> container;
        // 나머지 0~q-1
        vector<int> residue(q,-1);

        bool iscycle=false;
        int start_cycle=-1;

        int i=0;
        while(1){
            p*=10;
            if(residue[p%q]!=-1){
                if(container[residue[p%q]]==p/q){
                    start_cycle=residue[p%q];
                    iscycle=true;
                    break;
                }
                else{
                    residue[p%q]=i++;
                    container.push_back(p/q);
                }
            }
            else{
                residue[p%q]=i++;
                container.push_back(p/q);
                if(p%q==0) break;
            }
            p%=q;
        } 

        int sz=container.size();

        if(iscycle){
            for(int i=0;i<start_cycle;++i) printf("%d",container[i]);
            printf("(");
            for(int i=start_cycle;i<sz;++i) printf("%d",container[i]);
            printf(")");
        }
        else{
            for(int i=0;i<sz;++i) printf("%d",container[i]);
        }
        printf("\n");
    }
    return 0;
}