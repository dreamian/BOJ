#include <cstdio>
#include <cstring>
using namespace std;

int a[102];
int b[102];
int carry[102];
int sum[102];
char str[102];

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        for(int i=0;i<102;++i){
            a[i]=0; b[i]=0; carry[i]=0; sum[i]=0;
        }
        scanf("%s",str);
        int len_a=strlen(str);
        for(int i=len_a-1,j=0;i>=0;--i){
            a[j++]=str[i]-'0';
        }
        scanf("%s",str);
        int len_b=strlen(str);
        for(int i=len_b-1,j=0;i>=0;--i){
            b[j++]=str[i]-'0';
        }

        int max_len = len_a > len_b ? len_a : len_b;

        for(int i=0;i<=max_len;++i){
            sum[i]=a[i]+b[i]+carry[i];
            carry[i+1]=sum[i]/10;
            sum[i]%=10;
        }

        max_len = sum[max_len]==0 ? max_len-1 : max_len ;

        for(int i=max_len;i>=0;--i){
            printf("%d",sum[i]);
        }
        printf("\n");
    }
    return 0;
}