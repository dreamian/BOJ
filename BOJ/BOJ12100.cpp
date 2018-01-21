#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int n;
int max_v=-1;
int board[21][21];

void Search(int map[21][21],int cnt){
    if(cnt++==5) return;
    int temp[21][21];
    int empty[21][21];
    memset(empty,0,sizeof(empty));
    memcpy(temp,map,sizeof(int)*21*21);
    
    vector< deque< pair<int,bool> > > que(n);
    
    for(int cs=1;cs<=4;cs++){
        // East
        if(cs==1){
            for(int i=0;i<n;i++){
                for(int j=n-1;j>=0;j--){
                    if(temp[i][j]==0) continue;

                    if(que[i].empty()) que[i].push_back(mp(temp[i][j],false));
                    else if(temp[i][j]==que[i].back().first && !que[i].back().second){
                        que[i].pop_back();
                        que[i].push_back(mp(2*temp[i][j],true));
                    }
                    else{
                        que[i].push_back(mp(temp[i][j],false));
                    }
                    max_v=max(max_v,que[i].back().first);
                }
                int idx=n-1;
                while(!que[i].empty()){
                    int a=que[i].front().first;
                    que[i].pop_front();
                    empty[i][idx]=a;
                    idx--;            
                }
            }
            Search(empty,cnt);
            memset(empty,0,sizeof(empty));
        }
        // West
        if(cs==2){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(temp[i][j]==0) continue;

                    if(que[i].empty()) que[i].push_back(mp(temp[i][j],false));
                    else if(temp[i][j]==que[i].back().first && !que[i].back().second){
                        que[i].pop_back();
                        que[i].push_back(mp(2*temp[i][j],true));
                    }
                    else{
                        que[i].push_back(mp(temp[i][j],false));
                    }
                    max_v=max(max_v,que[i].back().first);
                }
                int idx=0;
                while(!que[i].empty()){
                    int a=que[i].front().first;
                    que[i].pop_front();
                    empty[i][idx]=a;
                    idx++;            
                }
            }
            Search(empty,cnt);
            memset(empty,0,sizeof(empty));
        }
        // South
        if(cs==3){
            for(int j=0;j<n;j++){
                for(int i=n-1;i>=0;i--){
                    if(temp[i][j]==0) continue;
            
                    if(que[j].empty()) que[j].push_back(mp(temp[i][j],false));
                    else if(temp[i][j]==que[j].back().first && !que[j].back().second){
                        que[j].pop_back();
                        que[j].push_back(mp(2*temp[i][j],true));
                    }
                    else{
                        que[j].push_back(mp(temp[i][j],false));
                    }
                    max_v=max(max_v,que[j].back().first);
                }
                int idx=n-1;
                while(!que[j].empty()){
                    int a=que[j].front().first;
                    que[j].pop_front();
                    empty[idx][j]=a;
                    idx--;            
                }
            }
            Search(empty,cnt);
            memset(empty,0,sizeof(empty));
        }
        // North
        if(cs==4){
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    if(temp[i][j]==0) continue;

                    if(que[j].empty()) que[j].push_back(mp(temp[i][j],false));
                    else if(temp[i][j]==que[j].back().first && !que[j].back().second){
                        que[j].pop_back();
                        que[j].push_back(mp(2*temp[i][j],true));
                    }
                    else{
                        que[j].push_back(mp(temp[i][j],false));
                    }
                    max_v=max(max_v,que[j].back().first);
                }
                int idx=0;
                while(!que[j].empty()){
                    int a=que[j].front().first;
                    que[j].pop_front();
                    empty[idx][j]=a;
                    idx++;            
                }
            }
            Search(empty,cnt);
        }
    }
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j]!=0) max_v=max(max_v,board[i][j]);
        }
    }
    Search(board,0);
    printf("%d\n",max_v);
    return 0;
}