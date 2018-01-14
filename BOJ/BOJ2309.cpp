#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr(9);
    int sum=-100;
    for(int i=0;i<9;i++) {scanf("%d",&arr[i]); sum+=arr[i];}
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(arr[i]+arr[j]==sum){
                arr.erase(arr.begin()+i);
                arr.erase(arr.begin()+j-1); 
                break;
            } 
        }
        if(arr.size()!=9) break;
    }
    sort(arr.begin(),arr.end());

    for(int i=0;i<7;i++) printf("%d\n",arr[i]);

    return 0;
}