#include <cstdio> 
using namespace std;

int n, ans, mid;
char map[50][50];

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&n);

        for(int i=1;i<=n;++i) scanf("%s",map[i]);

        int a;
        mid=n/2+1;
        ans=0;
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
            // up
            if(i<mid && mid-(i-1)<=j && j<=mid+(i-1)) ans+=map[i][j-1]-'0';
            // mid
            if(i==mid) ans+=map[i][j-1]-'0';
            // down
            if(i>mid && mid-(n-i)<=j && j<=mid+(n-i)) ans+=map[i][j-1]-'0';
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}