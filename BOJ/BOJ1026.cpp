#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    vector<int> A(n);
    vector<int> B(n);
    for(int i=0;i<n;++i) scanf("%d",&A[i]);
    sort(A.begin(),A.end());
    for(int i=0;i<n;++i) scanf("%d",&B[i]);
    sort(B.begin(),B.end());
    for(int i=0;i<n;++i) sum+=A[i]*B[n-1-i];
    printf("%d\n",sum);
    return 0;
}