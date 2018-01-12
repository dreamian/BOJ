#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int dist(pair<int, int> &p1,pair<int, int> &p2){
    int X=p1.x-p2.x;
    int Y=p1.y-p2.y;
    int cmp=X*X+Y*Y;
    return cmp;
}

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.y<p2.y;    
}

int main(){
    int n;
    scanf("%d",&n);
    vector< pair<int,int> > p(n);
    for(int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
    sort(p.begin(),p.end());
    int min_v=dist(p[0],p[1]);
    int start=2;
    vector< pair<int,int> > st(n);
    while(start<=n-1){
        for(int i=start-1;i>=0;i--){
            if(pow((p[start].x-p[i].x),2)<=min_v){
                // x좌표 차이가 d이하인 점들을 set에 넣음
                st.push_back(p[i]);
            }
            else break; 
        }
        for(auto it=st.begin();it!=st.end();){
            auto pt=*it;
            if(pow(pt.y-p[start].y,2)>min_v){
                st.erase(it);
            }
            else it++;
        }
        while(!st.empty()){
            int sz=st.size();
            min_v=min(min_v,dist(p[start],st[sz-1]));
            st.pop_back();
        }

        start++;
    }
    printf("%d\n",min_v);
}