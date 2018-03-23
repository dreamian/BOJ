#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct M{
    int n;
    int info[20][20];
    int optim;
    queue<int> que;
    M(): optim(-1) {}

    void get_info(){
        scanf("%d",&n);
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&info[i][j]);
    }
    int find_max_v(){
        int max_v=-1;
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) max_v=max(max_v,info[i][j]);
        return max_v;
    }
    void up(){
        for(int j=0;j<n;++j){
            for(int i=0;i<n;++i){
                if(info[i][j]==0) continue;
                que.push(info[i][j]);
                info[i][j]=0;
            }
            int mem=-1;
            int idx=0;
            while(!que.empty()){
                if(mem==-1){
                    mem=que.front();
                    que.pop();
                }
                else{
                    if(mem==que.front()){
                        que.pop();
                        info[idx++][j]=mem*2;
                        mem=-1;
                    }
                    else{
                        info[idx++][j]=mem;
                        mem=que.front();
                        que.pop();
                    }
                }
            }
            if(mem!=-1) info[idx][j]=mem;
        }
    }
    void down(){
        for(int j=0;j<n;++j){
            for(int i=n-1;i>=0;--i){
                if(info[i][j]==0) continue;
                que.push(info[i][j]);
                info[i][j]=0;
            }
            int mem=-1;
            int idx=n-1;
            while(!que.empty()){
                if(mem==-1){
                    mem=que.front();
                    que.pop();
                }
                else{
                    if(mem==que.front()){
                        que.pop();
                        info[idx--][j]=mem*2;
                        mem=-1;
                    }
                    else{
                        info[idx--][j]=mem;
                        mem=que.front();
                        que.pop();
                    }
                }
            }
            if(mem!=-1) info[idx][j]=mem;
        }
    }
    void left(){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(info[i][j]==0) continue;
                que.push(info[i][j]);
                info[i][j]=0;
            }
            int mem=-1;
            int idx=0;
            while(!que.empty()){
                if(mem==-1){
                    mem=que.front();
                    que.pop();
                }
                else{
                    if(mem==que.front()){
                        que.pop();
                        info[i][idx++]=mem*2;
                        mem=-1;
                    }
                    else{
                        info[i][idx++]=mem;
                        mem=que.front();
                        que.pop();
                    }
                }
            }
            if(mem!=-1) info[i][idx]=mem;
        }
    }
    void right(){
        for(int i=0;i<n;++i){
            for(int j=n-1;j>=0;--j){
                if(info[i][j]==0) continue;
                que.push(info[i][j]);
                info[i][j]=0;
            }
            int mem=-1;
            int idx=n-1;
            while(!que.empty()){
                if(mem==-1){
                    mem=que.front();
                    que.pop();
                }
                else{
                    if(mem==que.front()){
                        que.pop();
                        info[i][idx--]=mem*2;
                        mem=-1;
                    }
                    else{
                        info[i][idx--]=mem;
                        mem=que.front();
                        que.pop();
                    }
                }
            }
            if(mem!=-1) info[i][idx]=mem;
        }
    }
    void process(int cnt){
        if(cnt==5){
            int cmp=find_max_v();
            optim=max(optim,cmp);
            return;
        }
        int origin[20][20]={0,};
        memcpy(origin,info,sizeof(origin));

        up(); process(cnt+1); memcpy(info,origin,sizeof(origin));
        down(); process(cnt+1); memcpy(info,origin,sizeof(origin));
        left(); process(cnt+1); memcpy(info,origin,sizeof(origin));
        right(); process(cnt+1);
    }
}map;

int main(){
    map.get_info();
    map.process(0);
    printf("%d\n",map.optim);
}