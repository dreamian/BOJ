#include <iostream>
#include <cstdio>
typedef long long ll;

using namespace std;

int main(){
    ll yel_c, blue_c;
    ll y,g,b;
    cin >> yel_c >> blue_c;
    cin >> y >> g >> b;

    ll n_yel=-1;
    ll n_blue=-1;
    // int형끼리의 사칙연산에서 값이 over될 수 있으므로 ll형으로 선언하였다.
    n_yel=(2*y)+g-yel_c;
    if(n_yel<0) n_yel=0;
    
    n_blue=g+(3*b)-blue_c;
    if(n_blue<0) n_blue=0;
    
    ll a=n_yel+n_blue;
    cout << a << endl;

    return 0;
}