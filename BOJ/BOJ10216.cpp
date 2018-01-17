#include <bits/stdc++.h>
using namespace std;
#define ppii pair<int, pair<int,int> >
#define X(i,num) i[num].second.first
#define Y(i,num) i[num].second.second
#define R(i,num) i[num].first

// find : root node 탐색
int find(int i,vector<int> &par){
    if(par[i]==i) return i;
    else return par[i]=find(par[i],par);
}

// union : 같은 network에 있는 node merging
// j의 root값을 i의 root값으로 변경
// merge 될 때마다 cnt값 감소
void merge(int i,int j,vector<int> &par){
    int root_j=find(j,par);
    par[root_j]=find(i,par);
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector < ppii > comm(n);
        vector<int> par(n);
        // 0~n-1까지의 노드에 자신이 root인 정보를 par에 저장
        // comm에는 좌표값과 해당되는 반경 저장 
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&X(comm,i),&Y(comm,i),&R(comm,i));
            par[i]=i;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int X_sq=(X(comm,i)-X(comm,j))*(X(comm,i)-X(comm,j));
                int Y_sq=(Y(comm,i)-Y(comm,j))*(Y(comm,i)-Y(comm,j));
                int R_sq=(R(comm,i)+R(comm,j))*(R(comm,i)+R(comm,j));
                if(X_sq+Y_sq<=R_sq){
                    merge(i,j,par);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++) if(i==find(i,par)) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}