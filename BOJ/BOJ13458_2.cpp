#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX=1e+6;

int n, main_dir, sub_dir;
int student[MAX];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&student[i]);
    scanf("%d%d",&main_dir,&sub_dir);
    ll tot=n;

    for(int i=0;i<n;++i){
        student[i]-=main_dir;
        if(student[i]<=0) continue;
        int need=student[i]/sub_dir;
        if(need*sub_dir==student[i]) tot+=need;
        else tot+=need+1;
    }

    printf("%lld\n",tot);
}