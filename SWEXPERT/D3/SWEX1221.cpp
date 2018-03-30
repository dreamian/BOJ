#include <iostream> 
#include <algorithm>
using namespace std;

string num[10]={
    "ZRO",
    "ONE",
    "TWO",
    "THR",
    "FOR",
    "FIV",
    "SIX",
    "SVN",
    "EGT",
    "NIN"
};

int ans[10000];
int n;
string buf;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    for(int tc=1;tc<=t;++tc){
        cin >> buf;
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> buf;
            for(int j=0;j<10;++j){
                if(buf==num[j]){
                    ans[i]=j;
                    break;
                }
            }
        }

        sort(ans,ans+n);
        cout << '#' << tc << '\n';
        for(int i=0;i<n;++i){
            cout << num[ans[i]] << ' ';
        }

    }
}