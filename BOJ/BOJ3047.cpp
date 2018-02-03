#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    char buf[4];
    vector<int> info(3);
    scanf("%d%d%d",&info[0],&info[1],&info[2]);
    
    sort(info.begin(),info.end());
    scanf("%s",buf);
    for(int i=0;i<3;++i) printf("%d ",info[buf[i]-'A']);
    printf("\n");
    return 0;
}