#include <cstdio> 
#include <queue>
using namespace std;

queue<int> ans;

int main(){
    for(int tc;;){
        scanf("%d",&tc);
        printf("#%d ",tc);
        int it;
        for(int i=0;i<8;++i){
            scanf("%d",&it);
            ans.push(it);
        }
        bool get_ans=false;
        while(1){
            for(int i=1;i<=5;++i){
                int tar=ans.front();
                ans.pop();
                tar-=i;
                if(tar<=0){
                    tar=0;
                    get_ans=true;
                    ans.push(tar);
                    break;
                }
                ans.push(tar);
            }
            if(get_ans) break;
        }

        while(!ans.empty()) printf("%d ",ans.front()), ans.pop();
        printf("\n");
        if(tc==10) return 0;
    }
}