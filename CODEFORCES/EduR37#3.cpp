#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    char buf[n+1];
    scanf("%s",buf);

    int si=1e+9;
    for(int i=0;i<n-1;++i){
        if(buf[i]=='0'){
            if(i>=1 && buf[i-1]=='1'){
                // 구간 종결 조건
                sort(arr+si,arr+i+1);
            }
            si=1e+9;
        }
        else{
            si=min(i,si);
            if(i==n-2){
                sort(arr+si,arr+i+2);
            }
        }
    }

    bool flag=true;
    for(int i=0;i<n-1;++i){
        if(arr[i]==i+1) continue;
        flag=false;
        break;
    }


    flag ? printf("YES\n") : printf("NO\n");
}