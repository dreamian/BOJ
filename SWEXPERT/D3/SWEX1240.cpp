#include <cstdio> 
#include <cstring> 
using namespace std;

char password[10][8]={
    "0001101",
    "0011001",
    "0010011",
    "0111101",
    "0100011",
    "0110001",
    "0101111",
    "0111011",
    "0110111",
    "0001011"
};
char map[51][101];

char buf[8];
int code[8];

inline void proc(int idx, int start, int end){
    int code_c=0;
    int sum=0;

    for(int i=start;i<=end;i+=7){
        for(int j=i,cur=0;j<=i+6;++j,++cur) buf[cur]=map[idx][j];
        for(int k=0;k<10;++k){
            if(!strcmp(buf,password[k])){
                sum+=k;
                code[code_c++]=k;
                break;
            }
        }
    }
    int oddsum=code[0]+code[2]+code[4]+code[6];
    int evensum=code[1]+code[3]+code[5];
    int crit=oddsum*3+evensum+code[7];
    if(crit%10==0) printf("%d\n",sum);
    else printf("0\n");
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i) scanf("%s",map[i]);
        bool out=false;
        for(int i=0;i<n;++i){
            for(int j=m-1;j>=0;--j){
                if(map[i][j]=='1'){
                    proc(i,j-55,j);
                    out=true;
                    break;
                }
            }
            if(out) break;
        }
    }
    return 0;
}