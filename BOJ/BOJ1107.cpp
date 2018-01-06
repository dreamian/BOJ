#include <iostream>
#include <cmath>
using namespace std;

int num[11]={1,1,1,1,1,1,1,1,1,1,};

int size(int a){
    if(a==0) return 1;
    int sz=0;
    while(a!=0){
        a/=10;
        sz++;
    }

    return sz;
}

int gen(int size){
    int a=0;
    for(int i=1;i<=size;i++){
        a+=pow(10,i-1);
    }
    return a;
}

int main(){
    int obj,n;
    int ch=100;
    int cnt=0;

    cin >> obj >> n;

    int diff=abs(obj-ch); // 목표 채널과 현재 채널 간 차이

    int temp;
    for(int i=0;i<n;i++){ // 고장난 버튼의 값을 0으로 갱신
        cin >> temp;
        num[temp]=0;
    }
    int max=-1, min=10;
    for(int i=1;i<10;i++){ // 고장나지 않은 버튼의 min, max값 계산, 단 0은 제외
        if(num[i]!=0) max=max>i?max:i, min=min<i?min:i;
    }
    if(max==-1 || min==10){
        if(num[0]==0){
            cout << diff << endl; return 0; // 버튼이 다 고장나면 diff 출력 후 리턴
        }
        else{
            int a=diff<obj+1?diff:obj+1;
            cout << a << endl; return 0;
        }
    }

    int ch_l=0, ch_h=0;
    bool mem_l=1, mem_h=1;
    for(int i=size(obj);i>=1;i--){
        int k=obj/pow(10,i-1); 
            k%=10;  // 비교하려는 자릿수의 숫자
        for(int j=k;j<=9&&mem_h;j++){
            if(num[j]==1) {ch_h+=j*pow(10,i-1);
                           if(ch_h>=10 && num[0]==1 && ch_h%10!=0){
                               ch_h-=j*pow(10,i-1);
                           } 
                           break;
                          }
            else if(j==9) {mem_h=0; break;}
        }
        for(int j=k;j>=0&&mem_l;j--){
            if(num[j]==1) {ch_l+=j*pow(10,i-1); break;}
            else if(j==0){
                mem_l=0; break;
            }
        }
    }
    int ans;
    if(mem_l&&mem_h){ // 제한된 자릿수 내 최저 최대가 모두 존재하는 경우
        ans=size(obj);
        ans+=abs(ch_l-obj)>abs(ch_h-obj)?abs(ch_h-obj):abs(ch_l-obj);
        ans=ans<diff?ans:diff;
    }
    else if(mem_l){ // 제한된 자릿수 내 최저만 존재하는 경우
        ans=size(obj);
        ans+=abs(ch_l-obj);
        ans=ans<diff?ans:diff;
    }
    else if(mem_h){ // 제한된 자릿수 내 최대만 존재하는 경우
        ans=size(obj);
        ans+=abs(ch_h-obj);
        ans=ans<diff?ans:diff;
    }
    { // 제한된 자릿수 내 최저 최대가 모두 존재하지 않는 경우
        int key_n=size(obj)+1;   // 버튼을 누르는 횟수
        int key=0; // 버튼으로 이동된 숫자                
        key+=min*pow(10,size(obj));       
        if(num[0]!=1){
            key+=gen(size(obj))*min;
        }
        int cmp_n=size(obj)-1; // 버튼을 누른 횟수
        int cmp=0; // 버튼으로 이동된 숫자
        if(cmp_n==0){
            key_n=key_n+(key-obj)<diff?key_n+(key-obj):diff;
            ans=key_n<ans?key_n:ans;
        }
        else{
            cmp=max*pow(10,size(obj)-2);
            cmp+=gen(size(obj)-3)*max;
            key_n=key_n+(key-obj)<cmp_n+(obj-cmp)?key_n+(key-obj):cmp_n+(obj-cmp);
            key_n=key_n<diff?key_n:diff;
            ans=key_n<ans?key_n:ans;
        }
    }

    cout << ans << endl;
    return 0;
}