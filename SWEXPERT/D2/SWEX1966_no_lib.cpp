#include <cstdio>
using namespace std;

int n;
int arr[50];

inline void swap(int& a, int& b){
    a^=b;
    b^=a;
    a^=b;
}

inline void quick_sort(int arr[], int left, int right){
    // 종료 조건, 탐색 범위가 하나인 경우
    if(left==right) return;
    
    int ll=left;
    int rr=right;
    int pivot=arr[(ll+rr)/2];
    while(1){
        while(arr[ll]<pivot) ++ll;
        while(arr[rr]>pivot) --rr;
        if(ll==rr) break;
        if(arr[ll]==arr[rr]) ++ll;
        else swap(arr[ll],arr[rr]);
    }
    
    if(left<=ll-1) quick_sort(arr,left,ll-1);
    if(ll+1<=right) quick_sort(arr,ll+1,right);
}

int main(){
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",&arr[i]);
        quick_sort(arr,0,n-1);
        printf("#%d ",tc);
        for(int i=0;i<n;++i) printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}