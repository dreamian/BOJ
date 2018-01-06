#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    int n;
    string str;

    cin >> n;
    queue<int> q;
    int k=0;
    while(n--){
        cin >> str;
        if(str[0]=='p'){
            if(str[1]=='u'){
                cin >> k;
                q.push(k);
            }
            if(str[1]=='o'){
                if(q.empty()==1) cout << "-1" << endl;
                else{cout << q.front() << endl;
                q.pop();
                }
            }
        }
        else if(str[0]=='s') cout << q.size() << endl;
        else if(str[0]=='e') cout << q.empty() << endl;
        else if(str[0]=='f'){
            if(q.empty()){
                cout << "-1" << endl;
            }
            else{
                cout << q.front() << endl;
            }
        }
        else if(str[0]=='b'){
            if(q.empty()){
                cout << "-1" << endl;
            }
            else{
                cout << q.back() << endl;
            }
        }
    }
}