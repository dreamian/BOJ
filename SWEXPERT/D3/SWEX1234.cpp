#include <list> 
#include <iterator>
#include <cstdio> 
using namespace std;

int n;
list<int> ans;
list<int>::iterator iter;

int main(){
    //freopen("sample_input.txt","r",stdin);
    for(int tc=1;tc<=10;++tc){
        printf("#%d ",tc);
        scanf("%d ",&n);
        for(int i=0;i<n;++i){
            char tar;
            scanf("%c",&tar);
            ans.push_back(tar-'0');
        }
        
        while(1){
            int org=ans.size();
            for(iter=ans.begin();iter!=ans.end();){
                if(next(iter,1)==ans.end()){
                    ++iter;
                    continue;
                }
                if(*iter==*next(iter)){
                    ans.erase(iter);
                    ans.erase(next(--iter));
                }
                else{
                    ++iter;
                }
            }

            if(org==ans.size()) break;
        }
        
        for(iter=ans.begin();iter!=ans.end();++iter){
            printf("%d",*iter);
        }
        printf("\n");
        ans.clear();
    }
}