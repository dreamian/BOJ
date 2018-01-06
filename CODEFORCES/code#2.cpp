#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;

using namespace std;

int main(){
    ll n,k;
    cin >> n >> k;

    if(k==1) {cout << n << endl; return 0;}
    int cnt=0;
    while(n!=1){
        n/=2;
        cnt++;
    }


  //  int cnt=floor(log2(n)+1e-30); WA를 받은 부분
    
    
    cout << (1LL << (cnt+1))-1 << endl;

    return 0;
}