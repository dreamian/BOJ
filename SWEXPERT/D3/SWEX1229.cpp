#include <iostream>
#include <list> 
#include <iterator>
using namespace std;

list<string> ans;
list<string>::iterator iter;
string buf;
int n, ord;
int x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int tc=1;tc<=10;++tc){
        cin >> n;
        while(n--){
            cin >> buf;
            ans.push_back(buf);
        }
        cin >> ord;

        while(ord--){
            char a;
            while(1){
                cin >> a;
                if(a=='I'||a=='D') break;
            }
            
            cin >> x >> y;
            iter=next(ans.begin(),x);
            if(a=='I'){
                while(y--){
                    cin >> buf;
                    ans.insert(iter,buf);
                }
            }
            else{
                while(y--){
                    ans.erase(iter);
                    iter=next(--iter);
                }
            }
        }    

        ans.resize(10);

        cout << '#' << tc << ' ';

        for(iter=ans.begin();iter!=ans.end();++iter){
            cout << *iter << ' ';
        }
        cout << '\n';

        if(tc==10) break;
        ans.clear();
    }
    return 0;
}