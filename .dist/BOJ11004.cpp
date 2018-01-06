#include <cstdio>
#include <algorithm>
using namespace std;
#define max 5000000

int arr[max+1];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    nth_element(arr,arr+k-1,arr+n);

    printf("%d\n",arr[k-1]);
}