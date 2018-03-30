#include <cstdio> 
using namespace std;

int map[100][101];
int n, ans;

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&map[i][j]);
        // column  search
        for(int j=0;j<n;++j){
            int mem=-1;
            for(int i=0;i<n;++i){
                if(map[i][j]==0) continue;

                if(map[i][j]==2){
                    if(mem==-1 || mem==2) continue;
                    else ++ans, mem=-1;
                }
                else mem=1;
            }
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}