#include <iostream>
#include <string>
using namespace std;

string s;

int main(){
    //freopen("sample_input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int tc=1;tc<=t;++tc){
        cin >> s;
        int len=s.length();
        int ss=0;
        int ee=len-1;
        bool possible=true;
        while(ss<=ee){
            if(s[ss]==s[ee]){
                ++ss;
                --ee;
            }
            else{
                possible=false;
                break;
            }
        }
        cout << '#' << tc << ' ' << possible << '\n'; 
    }
    return 0;
}