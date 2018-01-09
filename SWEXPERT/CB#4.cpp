#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;

    scanf("%d",&t);

    for(int test=1;test<=t;test++){
        int n=0;
        scanf("%d",&n);
        int k=n;
        if(n==1 || n==2) printf("#%d -1\n",test);
        else if(n==3) printf("#%d 1\n",test);
        else{
            int cmp=n; // n을 최대한 작게 factorizing
            double tmp=sqrt(cmp);
            int tmp_2=sqrt(cmp);
            while(tmp==tmp_2){
            if(tmp==double(tmp_2)) cmp=sqrt(cmp);
            tmp=sqrt(cmp);
            tmp_2=sqrt(cmp);
            }
            int prime=1;
            vector<int> p;
            int a=ceil(sqrt(n))+1;
            for(int i=2;i<=a;i++){
            if(n==1) break;
            while(1){
                if(n%i==0){
                    if(p.empty() || p.back()!=i) {prime*=i; p.push_back(i);}
                    n/=i;
                }
                else{
                    break;
                }
            }
            if(i%2==1) i++;
            }
            if(prime==1) printf("#%d 1\n",test);
            else{
            bool flag=false;
            if(2<=prime && prime<k) flag=true;


            printf("#%d ",test);
            flag?printf("-1\n"):printf("2\n");
            }
        }
    }
}