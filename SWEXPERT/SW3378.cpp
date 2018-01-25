#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <tuple>
using namespace std;

string mas[10];
string me[10];
char buf[81];

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;++test){
        printf("#%d ",test);
        int a,b;
        scanf("%d %d",&a,&b);

        vector< tuple<int, int, int, int> > equations;
        int r_n=0, c_n=0, s_n=0;

        // master string 저장
        for(int i=0;i<a;++i){
            scanf("%s",buf);
            mas[i].assign(buf);
            int sz=mas[i].length();

            int cnt=0;
            bool flag=false;
            int j=0;
            for(;!flag;++j){
                if(mas[i][j]=='.') ++cnt;
                else flag=true;
            }

            equations.emplace_back(r_n,c_n,s_n,cnt);
            --j;
            for(;j<sz;++j){
                if(mas[i][j]=='(') ++r_n;
                else if(mas[i][j]=='{') ++c_n;
                else if(mas[i][j]=='[') ++s_n;
                else if(mas[i][j]==')') --r_n;
                else if(mas[i][j]=='}') --c_n;
                else if(mas[i][j]==']') --s_n;
            }
        }

        vector< tuple<int, int, int> > sols;        

        for(int r=1;r<=20;r++)for(int c=1;c<=20;c++)for(int s=1;s<=20;s++){
            bool impos=false;
            for(const auto& equ : equations){
                int cntr, cntc, cnts, val;
                tie(cntr, cntc, cnts, val)=equ;
                if(cntr*r+cntc*c+cnts*s!=val){
                    impos=true;
                    break;
                }
            }
            if(!impos){
                sols.emplace_back(r,c,s);
            }
        }

        r_n=0, c_n=0, s_n=0;
        for(int i=0;i<b;++i){
            scanf("%s",buf);
            me[i].assign(buf);

            set<int> res;
            for(const auto& sol : sols){
                int r,c,s;
                tie(r,c,s)=sol;
                res.insert(r*r_n+c*c_n+s*s_n);
            }

            printf("%d ",(res.size()==1)? *res.begin():-1);

            for(int j=0;j<me[i].length();j++){
                if(me[i][j]=='(') ++r_n;
                else if(me[i][j]=='{') ++c_n;
                else if(me[i][j]=='[') ++s_n;
                else if(me[i][j]==')') --r_n;
                else if(me[i][j]=='}') --c_n;
                else if(me[i][j]==']') --s_n;
            }
        }
        printf("\n");
    }
}