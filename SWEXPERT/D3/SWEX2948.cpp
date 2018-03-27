#include <iostream> 
#include <set>
using namespace std;

string buf;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    for(int tc=1;tc<=t;++tc){
        set<string> proc;
        int a,b;
        cin >> a >> b ;
        while(a--){
            cin >> buf;
            proc.insert(buf);
        }
        int cnt=0;
        int sz=proc.size();
        while(b--){
            cin >> buf;
            proc.insert(buf);
            if(sz==proc.size()) ++cnt;
            else ++sz;
        }
        cout << '#' << tc << ' ' << cnt << '\n';
    }
    return 0;
}