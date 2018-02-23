#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i) scanf("%d",&arr[i]);
    sort(arr.begin(),arr.end());
    printf("%d",arr[n/2]);
}