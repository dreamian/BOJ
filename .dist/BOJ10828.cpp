#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(){
    stack<int> st;
    string str;
    int n;
    int k;
    cin >> n;
    while(n--){
        cin >> str;
        if(str[0]=='p'){
            if(str[1]=='u'){
                cin >> k;
                st.push(k);
            }
            if(str[1]=='o'){
                if(st.empty()==1) cout << "-1" << endl;
                else{cout << st.top() << endl;
                st.pop();
                }
            }
        }
        else if(str[0]=='s') cout << st.size() << endl;
        else if(str[0]=='e') cout << st.empty() << endl;
        else if(str[0]=='t'){
            if(st.empty()){
                cout << "-1" << endl;
            }
            else{
                cout << st.top() << endl;
            }
        } 
    }
}