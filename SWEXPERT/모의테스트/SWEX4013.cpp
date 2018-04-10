#include <cstdio>
using namespace std;

int s[4];
int ans;

inline void rotate_(int i, int dir){
    int mem = dir==1 ? ((1<<7)&s[i])/(1<<7) : ((1<<0)&s[i])*(1<<7) ;
    s[i] = dir==1 ? s[i]<<1 : s[i]>>1 ;
    s[i]+=mem;
    s[i]-=s[i]&(1<<8);
}

inline void dfs(int num, int mov, int dir){
    int nnum=num+mov;
    if(nnum!=-1 || nnum!=4){

        const int crit = mov==1 ? 2 : 6 ;

        int cur=((s[num]&(1<<crit))==(1<<crit));
        int next=((s[nnum]&(1<<(crit+4)%8))==(1<<(crit+4)%8));
        if(cur^next) dfs(nnum,mov,-dir);    

    }
    rotate_(num,dir);
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        ans=0;
        int k;
        scanf("%d",&k);
        for(int i=0;i<4;++i) s[i]=0;
        for(int i=0;i<4;++i) for(int j=0;j<8;++j){
            int a;
            scanf("%d",&a);
            s[i]+=a<<j;
        }
        int num, dir;
        while(k--){
            scanf("%d%d",&num,&dir);
            --num;
            int cur, next;
            // left
            if(num>=1){
                cur=((s[num]&(1<<6))==(1<<6));
                next=((s[num-1]&(1<<2))==(1<<2));
                if(cur^next) dfs(num-1,-1,-dir);
            }
            // right
            if(num<=2){
                cur=((s[num]&(1<<2))==(1<<2));
                next=((s[num+1]&(1<<6))==(1<<6));
                if(cur^next) dfs(num+1,1,-dir);
            }
            rotate_(num,dir);
        }
        for(int i=0;i<4;++i) ans+=(s[i] & 1)*(1<<i);
        printf("#%d %d\n",tc,ans); 
    }
    return 0;
}