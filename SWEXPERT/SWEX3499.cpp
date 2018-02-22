#include <iostream>
#include <string>
#include <vector>
using namespace std;

string buf;

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    cin >> t;
    for(int tc=1; tc<=t;++tc){
        int n;
        cin >> n;
        vector<string> deck(n);
        for(int i=0;i<n;++i){
            cin >> deck[i];
        }
        cout << '#' << tc << ' ';
        
        int shuf=n/2;
        if(n%2==1) ++shuf;

        for(int i=0;i<shuf;i++){
            cout << deck[i] << ' ';
            if(i+shuf<n) cout << deck[i+shuf] << ' ';
        }
        cout << '\n';
    }
    return 0;
}