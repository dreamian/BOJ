#include <cstdio>
#include <cstring>
using namespace std;

char s1[1001], s2[1001];
short lcs[1001][1001];

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        scanf("%s %s",s1,s2);
        int len1=strlen(s1), len2=strlen(s2);

        for(int i=0;i<len1;++i) for(int j=0;j<len2;++j){
            if(s1[i]==s2[j]){
                if(i!=0 && j!=0) lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j]=1;
            }
            else{
                if(i!=0 && j!=0) lcs[i][j]= lcs[i-1][j] > lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
                else if(i==0) lcs[i][j]=lcs[i][j-1];
                else if(j==0) lcs[i][j]=lcs[i-1][j];
                else lcs[i][j]=0;
            }
        }

        printf("%hd\n",lcs[len1-1][len2-1]);
    }
    return 0;
}