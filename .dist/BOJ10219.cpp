#include <iostream>
#include <cstring>
using namespace std;

char grill[12][12];

int main(){
    int t,h,w;
    cin >> t;
    while(t--){
        memset(grill,0,sizeof(grill));
        cin >> h >> w;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> grill[i][j];
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=w;j>=1;j--){
                cout << grill[i][j];
            }
            cout << endl;
        }
        

    }
}