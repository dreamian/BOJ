/*
bit shift 연산 이용
접근 방식

-  저장할 비트는 총 10자리를 가지도록 함.
    (맨 마지막과 맨 앞은 0으로 둔다. 쿼리가 생길 경우 해당 비트값에 1이 저장되면
    반대 값을 1로 바꾼다)
*/
#include <cstdio>
using namespace std;

char buf[9];
// 12시 1<<8
int t[4];
bool connect[3];

int make_dir(int i, int tar, int dir){
    int diff=tar-i;
    int cnt=0;

    if(diff==0) return dir;
    else if(diff>0){
        for(int idx=i;idx<tar;++idx){
            ++cnt;
            if(!connect[idx]) return -2;
        }
    }
    else{
        for(int idx=tar;idx<i;++idx){
            ++cnt;
            if(!connect[idx]) return -2;
        }
    }

    if(cnt%2==0) return dir;
    else return -dir;
}

int main(){
    // 상태 저장
    for(int i=0;i<4;++i){
        scanf("%s",buf);
        for(int j=0;j<8;++j){
            if(buf[j]=='1') t[i]+=1<<(8-j); 
        }
    }
    int m;
    scanf("%d",&m);
    while(m--){
        int tar,dir;
        scanf("%d%d",&tar,&dir);
        --tar;
        // 각 톱니바퀴의 연결 조건을 확인해야 합니다
        const int mat=6;
        for(int i=0;i<3;++i){
            bool A=(t[i]&(1<<mat)) == 1<<mat;
            bool B=(t[i+1]&(1<<(mat+4)%8)) == 1<<(mat+4)%8;
            if(A!=B) connect[i]=true;
            else connect[i]=false;
        }
        // 톱니바퀴를 회전합니다
        for(int i=0;i<4;++i){
            int d=make_dir(i,tar,dir);
            if(d==-2) continue;
            else if(d==1){
                t[i]>>=1;
                if((t[i]&1) == 1){
                    t[i]-=1<<0;
                    t[i]+=1<<8;
                }
            }
            else{
                t[i]<<=1;
                if((t[i]&(1<<9)) == 1<<9){
                    t[i]-=1<<9;
                    t[i]+=1<<1;
                }
            } 
        }
    }
    int ans=0;
    for(int i=0;i<4;++i){
        if( (t[i]&(1<<8)) == (1<<8) ) ans+=(1<<i);
    }
    printf("%d\n",ans);
}